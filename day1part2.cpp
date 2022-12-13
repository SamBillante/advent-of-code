#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//calorie counter (find highest)
//AND track a "leaderboard" of the top three

int main (int argc, char **argv) {

    ifstream in(argv[1]);
    unsigned int maxCals[] = {0, 0, 0};
    unsigned int elfTotal;
    string cal;

    while(in.peek() != EOF) {
        getline(in, cal);
        if(!isdigit(cal.at(0))) {
            for(int i = 0; i < 3; i++) {
                if(elfTotal > maxCals[i]) {
                maxCals[i] = elfTotal;
                break;
                }
            }
            elfTotal = 0;
        } else {
            elfTotal += stoi(cal);
        }
        //cout << cal << endl;
    }
    
    cout << (maxCals[0] + maxCals[1] + maxCals[2]);

    return 0;
}