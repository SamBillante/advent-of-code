#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    char buffer;
    int lowL, highL, lowR, highR;
    unsigned int count = 0;
    
    while(in >> lowL) {
        //in >> lowL;
        in >> buffer >> highL >> buffer >> lowR >> buffer >> highR;

        if((lowL >= lowR && lowL <= highR) || (highL >= lowR && highL <= highR)
        || (lowR >= lowL && lowR <= highL)) {
            count++; //first two statements together check if the ranges overlap partially or if the first range is contained in the second.
        } //the part after the second or checks if the second range is contained in the first.

    }
    //cout << lowL << " " << highL << " " << lowR << " " << highR;
    cout << count;
    return 0;
}