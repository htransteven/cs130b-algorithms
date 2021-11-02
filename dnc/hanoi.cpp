#include <iostream>
#include "../global_inputs.h"
#include "string"
#include <vector>
#include <unordered_map>

using namespace std;

int numDiscs = 3;
string start = "A";
string dst = "B";
string tmp = "C";
int moves = 0;

void input_callback(int argc, char* argv[], int index) {
    string token = argv[index];
    if(token == "-n") {
        numDiscs = stoi(argv[index + 1]);
    } else if (token == "-start") {
        start = argv[index + 1];
    } else if (token == "-dest") {
        dst = argv[index + 1];
    } else if (token == "-temp") {
        tmp = argv[index + 1];
    }
}

unordered_map<string, vector<int>> pegs = {
    {start, vector<int>()},
    {dst, vector<int>()},
    {tmp, vector<int>()},
};

/*
    Divide-and-Conquer Analysis:
    src = A, dest = B, temp = C, n = discs = 3
    1. Move top disc of A to B
    2. Move top disc of A to C
    3. Move top disc of B to C
    4. Move top disc of A to B
    5. Move top disc of C to A
    6. Move top disc of C to B
    7. Move top disc of A to B

    Steps 1-3 is ultimately saying move n-1 discs to the "temporary" peg
    Step 4 is saying to move the final nth peg to the destination peg
    Steps 5-7 is saying move n-1 discs from the "temporary" peg to the destination peg
    
    When n = 1, the only move is to move the disc from start peg to destination peg
*/
void dnc_hanoi(string src, string dest, string temp, int discs) {
    if(discs == 0) return;
    dnc_hanoi(src, temp, dest, discs - 1);
    moves++;
    if(verbose) cout << "Move #" << moves << ": disc " << pegs.at(src).back() << " from " << src << " to " << dest << endl;
    pegs.at(dest).push_back(pegs.at(src).back());
    pegs.at(src).pop_back();
    dnc_hanoi(temp, dest, src, discs - 1);
}

int main (int argc, char* argv[]) {
    if(!load_global_inputs(argc, argv, input_callback)) return 1;
    
    cout << "Divide and Conquer: Tower of Hanoi" << endl;
    cout << "Parameters:" << endl;
    cout << "\tNumber of pegs: 3" << endl;
    cout << "\tNumber of discs: " << numDiscs << endl;
    cout << "\tStarting Peg: " << start << endl;
    cout << "\tDestination Peg: " << dst << endl;
    cout << "\tTemporary Peg: " << tmp << endl << endl;

    // Load all the discs to pegA
    // higher number = larger disc
    for(int i = numDiscs; i > 0; i--) {
        pegs.at(start).push_back(i);
    }

    dnc_hanoi(start, dst, tmp, numDiscs);
    cout << "It took " << moves << " moves to move " << numDiscs << " discs from peg " << start << " to peg " << dst << endl;

    return 0;
}