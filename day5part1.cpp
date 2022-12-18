#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

void buildStacks(ifstream &in, stack<char> boxes[], int rows) { 
    string temp;
    getline(in, temp);
    //cout << temp;
    if(rows == 0) return;
    
    buildStacks(in, boxes, rows - 1);
    for(int i = 0; i < 9; i++) { //assumes columns = 9
        if(!(isblank(temp.at(i * 4 + 1)))) {
            boxes[i].push(temp.at(i * 4 + 1));
            //cout << temp.at(i * 4 + 1);
        }
    }
}

void craneMove(int num, int start, int dest, stack<char> boxes[]) {
    stack<char> temp;
    for(int i = 0; i < num; i++) {
        if(boxes[start].empty()) break;

        boxes[dest].push(boxes[start].top());
        boxes[start].pop();
    }
}

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    istringstream iss;
    string buffer;
    int numToMove, start, dest;
    stack<char> stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9;
    stack<char> boxes[] = {stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9};
    buildStacks(in, boxes, 8);

    //get rid of empty bits
    getline(in, buffer);
    cout << buffer;

    while(in.peek() != EOF) {
        getline(in, buffer);
        iss.str(buffer);
        iss >> buffer >> numToMove >> buffer >> start >> buffer >> dest;
        craneMove(numToMove, start - 1, dest - 1, boxes);
    }

    for(int i = 0; i < 9; i++) {
        if(boxes[i].empty()) {
            cout << "[ ] ";
        } else
        cout << "[" << boxes[i].top() << "] ";
    }
    in.close();
    return 0;
}