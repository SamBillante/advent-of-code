#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//program to compute the answer for day 2 part 2 of advent of code.
//this program is needlessly complex, but could be easily adapted to solve a similar problem with more options

class Sign { //you either throw rock, paper, or scissors.
public:
    Sign* beats;
    Sign* losesTo;
    int val;
    Sign(int val);
    void setNeighbors(Sign* beats, Sign* losesTo) {
        this->losesTo = losesTo;
        this->beats = beats;
    }
};

Sign::Sign(int val) {
    beats = nullptr;
    losesTo = nullptr;
    this->val = val;
}

int main(int argc, char **argv) { // argv[1] should be the input file
    ifstream in(argv[1]);
    unsigned int score = 0;
    char opPlay, myPlay; //opPlay is opponent play and represents rock, paper, or scissors. myPlay represents a win, loss or tie
    Sign rock(1), paper(2), scissors(3);
    rock.setNeighbors(&scissors, &paper);
    paper.setNeighbors(&rock, &scissors);
    scissors.setNeighbors(&paper, &rock);
    Sign* opSign;

    while(in >> opPlay) {
        if(opPlay == 'A') opSign = &rock;
        if(opPlay == 'B') opSign = &paper;
        if(opPlay == 'C') opSign = &scissors;

        in >> myPlay;
        if(myPlay == 'Y') score += 3 + (*opSign).val; //tie is worth 3 points. playVal = opPlay - 64
        else { 
            if(myPlay== 'Z') {
                score += 6 + (*opSign).losesTo->val; //win is worth 6 points
            }
            else {
                if(myPlay == 'X') {
                    score += (*opSign).beats->val; //loss is worth nothing
                }
            }
        }
    }
    cout << score;
    return 0;
}
