#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    string sack;
    int split;
    char dupe;
    unsigned int count = 0;
    //int test = 0;

    while(in >> sack) {
        split = sack.length() / 2;        
        for(int i = 0; i < split; i++) {
            for(int j = split; j < split * 2; j++) {
                if(sack.at(i) == sack.at(j)) {
                    dupe = sack.at(i);
                    //cout << dupe << " ";
                    i = split;
                    break;
                    //test++;
                }
            }
        }
        if(dupe > 96) count += dupe - 96;
        if(dupe < 96) count += dupe - 38;
    }
    cout << count;
    //cout << " " << test;
    return 0;
}