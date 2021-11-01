#include <iostream>
#include "global_inputs.h"
#include "string"

using namespace std;

bool verbose = false;
string input_file_name = "";
string output_file_name = "";

// returns true if successful
bool load_global_inputs(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++) {
        string token = argv[i];
        if(token == "-v") {
            verbose = true;
        } else if (token == "-f") {
            if(i + 1 == argc) {
                cerr << "error: must provide a filename when using -f" << endl;
                return false;
            }

            input_file_name = argv[i + 1];
            i++;
        }
    }

    return true;
}