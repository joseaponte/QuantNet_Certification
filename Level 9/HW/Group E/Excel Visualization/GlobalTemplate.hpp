//GlobalTemplate.hpp is the header file that declares 
//global template functions for the Group A,B project
#ifndef GLOBAL_TEMPLATE_HEADER					//If GLOBAL_TEMPLATE_HEADER is undefined
#define GLOBAL_TEMPLATE_HEADER					//Define it

#include "EuropeanOption.hpp"					//Include EuropeanOption header file

//Declaring global fucntion that produces a mesh array 
//of doubles separated by a mesh size h
template <typename T>
std::vector<double> Mesh(const T& Opt, const double& start_val, const double& end_val, const double& h_3, const char& which_type);

#ifndef GLOBAL_TEMPLATE_CPP						//GLOBAL_TEMPLATE_CPP isn't defined yet
#include "GlobalTemplate.cpp"					//Include GlobalTemplate source file
#endif
#endif