#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//calorie counter (find highest)

int main (int argc, char **argv) {

    ifstream in(argv[1]);
    unsigned int maxCals = 0;
    unsigned int elfTotal;
    string cal;

    while(in.peek() != EOF) {
        getline(in, cal);
        if(!isdigit(cal.at(0))) {
            if(elfTotal > maxCals) maxCals = elfTotal;
            elfTotal = 0;
        } else {
            elfTotal += stoi(cal);
        }
        //cout << cal << endl;
    }
    
    cout << maxCals;

    return 0;
}