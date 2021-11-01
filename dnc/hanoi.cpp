#include <iostream>
#include "../global_inputs.h"
#include "string"
#include <functional>

using namespace std;

int numPegs = 0;

void input_callback(int argc, char* argv[], int index) {
    string token = argv[index];
    if(token == "-n") {
        numPegs = stoi(argv[index + 1]);
    }
}

int main (int argc, char* argv[]) {
    if(!load_global_inputs(argc, argv, input_callback)) return 1;
    
    cout << numPegs << endl;
    return 0;
}