#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//program to compute the answer for day 2 part 1 of advent of code

int main(int argc, char **argv) { // argv[1] should be the input file
    ifstream in(argv[1]);
    unsigned int score = 0;
    char opPlay, myPlay; //chars that represent rock, paper, or scissors. opPlay is opponent play.

    while(in >> opPlay) {
        in >> myPlay;
        if(myPlay - opPlay == 23) score += 3 + (myPlay - 87); //tie is worth 3 points
        else { 
            if(myPlay - opPlay == 24 || myPlay - opPlay == 21) score += 6 + (myPlay - 87); //win is worth 6 points
            else {
                if(myPlay - opPlay == 22 || myPlay - opPlay == 25) score += (myPlay - 87); //loss is worth nothing
            }
        }
        //my - op = 23 means tie
        //my - op = 24 means win, or my - op = 21
        //my - op = 22 means loss, or my - op = 25
    }
    cout << score;
    return 0;
}