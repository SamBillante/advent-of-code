#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    string sack1, sack2, sack3;
    char dupe;
    unsigned int count = 0;
    //int test = 0;

    while(in >> sack1) {
        in >> sack2;
        in >> sack3;
        for(int i = 0; i < sack1.length(); i++) {
            if(sack2.find(sack1.at(i)) != -1) {
                if(sack3.find(sack1.at(i)) != -1) {
                    dupe = sack1.at(i);
                    //cout << dupe << " ";
                    //test++;
                    break;
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