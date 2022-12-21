#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Layer {
public:
    unsigned int value = 0;
    Layer* parent;

    Layer(Layer *parent);
};

Layer::Layer(Layer *parent) {
    this->parent = parent;
}

int main (int argc, char **argv) {
    ifstream in(argv[1]);
    unsigned int min = 70000000; //the smallest directory size above a particular size
    Layer* cur = new Layer(nullptr);
    Layer* last;
    string line, number;
    int linesRead = 0;
    int cd = 0;
    unsigned int spaceNeeded = 30000000 - (70000000 - 46876531);

    while(in.good()) {
        linesRead++;
        getline(in, line);
        if(line.at(2) == 'c') {//command is cd
            cd++;
            if(line.at(5) == '.')  {//command is cd ..
                //up a layer
                if(cur->value >= spaceNeeded && cur->value < min) {
                    cout << "candidate at line " << linesRead << endl;
                    min = cur->value;
                }
                last = cur;
                cur = cur->parent;
                cur->value += last->value;
                delete last;
            } 
            else { //command cd's into a directory
                //down a layer
                cur = new Layer(cur);
            } 
        }
        if(isdigit(line.at(0))) {//file found by ls
            //add the value here to the current layer
            number = line.substr(0, line.find(' '));
            cur->value += stoi(number);
            //cout << "^" << number << "^" << endl;
            //break;
        }
    }
    //while loop that goes up layers
    while(cur->parent != nullptr) {
        //up a layer
        if(cur->value >= 16876531 && cur->value < min) {
            min = cur->value;
            cout << "found at end: ";
        }
        last = cur;
        cur = cur->parent;
        cur->value += last->value;
        delete last;
    }
    //cout result
    cout << linesRead << "/1051 lines read" << endl;
    cout << cd << "/379 cd's detected" << endl;
    cout << min;

    return 0;
}