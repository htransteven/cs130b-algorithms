#include <iostream>
#include "../global_inputs.h"

using namespace std;

int main (int argc, char* argv[]) {
    if(!load_global_inputs(argc, argv)) return 1;

    return 0;
}