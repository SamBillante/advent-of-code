#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void pushWindow(ifstream &in, int distance, char last3[], char cur) {
    last3[0] = last3[1];
    last3[1] = last3[2];
    last3[2] = cur;
    for(int i = 0; i < distance; i++) {
        last3[0] = last3[1];
        last3[1] = last3[2];
        in >> last3[2];
    }
}

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    //istringstream iss("nppdvjthqldpwncqszvftbrmjlhg");
    char last3[3];
    char cur;
    unsigned int count = 3;
    in >> last3[0] >> last3[1] >> last3[2];
    while(in >> cur) {
        for(int i = 2; i > -1; i--) {
            if(cur == last3[i]) {
                pushWindow(in, i, last3, cur);
                count += i + 1;
                break;
            }
            if(i == 0) {
                if(last3[2] == last3[1]) {
                    pushWindow(in, 1, last3, cur);
                    count += 2;
                    break;
                }
                if(last3[1] == last3[0] || last3[2] == last3[0]) {
                    pushWindow(in, 0, last3, cur);
                    count++;
                    break;
                }
                cout << count + 1;
                cout << "  Last 4: " << last3[0] << last3[1] << last3[2] << cur;
                return 0;
            }
        }
    }
    cout << "no sequence found.";
    return 0;
}