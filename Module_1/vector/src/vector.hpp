#ifndef AALTO_ELEC_CPP_VECTOR
#define AALTO_ELEC_CPP_VECTOR

#include <vector>

/* These functions return the minimum, maximum and the average value
of a vector. The vector must always have at least one element -
if an empty vector is passed to these functions, the behaviour is undefined.
*/

int GetMin(std::vector<int> v);
int GetMax(std::vector<int> v);
double GetAvg(std::vector<int> v);

#endif

