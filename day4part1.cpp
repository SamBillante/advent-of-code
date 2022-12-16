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

        if((lowL <= lowR && highL >= highR) || (lowR <= lowL && highR >= highL)) {
            count++; //if one range is contained in the other, increment count
        }
    }
    in.close();
    //cout << lowL << " " << highL << " " << lowR << " " << highR;
    cout << count;
    return 0;
}