#ifndef _GLOBAL_INPUTS_
#define _GLOBAL_INPUTS_

#include "string"

extern bool verbose;
extern std::string input_file_name;
extern std::string output_file_name;

bool load_global_inputs(int argc, char* argv[]);

#endif