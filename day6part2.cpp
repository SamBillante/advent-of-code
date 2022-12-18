#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int pushWindow(ifstream &in, int distance, char last[], char cur) {
    for(int i = 0; i < 12; i++) {
        last[i] = last[i+1];
    }
    last[12] = cur;

    for(int i = 0; i < distance; i++) {
        for(int j = 0; j < 12; j++) {
            last[j] = last[j+1];
        }
        in >> last[12];
    }
    return distance + 1;
}

int checkCandidate(ifstream &in, char candidate[], char cur) {
    int i;
    bool found = false;
    for(i = 11; i > -1 && !found; i--) {
        for(int j = 12; j > i; j--) {
            if(candidate[i] == candidate[j]) {
                found = true;
                break;
            }
        }
    }
    if(found) { //if a match is found and the candidate fails, push the window
        return pushWindow(in, i + 1, candidate, cur); //has to be +1 becasue the i-- will happen before found is checked.
    }
    return -1; //else return -1 to signify that this candidate succeeded.
}

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    //istringstream in("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
    char last13[13];
    char cur;
    int testResult;
    unsigned int count = 13;
    for(int i = 0; i < 13; i++) {
        in >> last13[i];
    }
    while(in >> cur) {
        for(int i = 12; i > -1; i--) {
            if(cur == last13[i]) {
                count += pushWindow(in, i, last13, cur);
                break;
            }
            if(i == 0) {
                testResult = checkCandidate(in, last13, cur);
                if(testResult == -1) {
                    cout << count + 1;
                    cout << "  Last 14: ";
                    for(int j = 0; j < 13; j++) {
                        cout << last13[j];
                    }
                    cout << cur;
                    return 0;
                }
                count += testResult;
                break;
            }
        }
    }
    cout << "no sequence found.";
    return 0;
}