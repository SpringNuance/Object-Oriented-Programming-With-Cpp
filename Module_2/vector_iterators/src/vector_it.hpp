#ifndef AALTO_ELEC_CPP_VECTOR_IT
#define AALTO_ELEC_CPP_VECTOR_IT

#include <vector>

// Reads a set of integers into a vector. Stops when user gives something other than an integer. 
std::vector<int> ReadVector();

// Prints the sum of each pair of adjacent elements: input: 1 2 3 4 !\n, output: 3 5 7 \n
// The vector should not be modified and is thus declared as a const
void PrintSum1(const std::vector<int>& v);

// Prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
void PrintSum2(const std::vector<int>& v);

#endif
