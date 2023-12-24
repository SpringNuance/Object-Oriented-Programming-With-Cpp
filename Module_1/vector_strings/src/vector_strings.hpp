#ifndef AALTO_ELEC_CPP_VECTOR_STRINGS
#define AALTO_ELEC_CPP_VECTOR_STRINGS

#include <vector>
#include <string>

void CMDReader();
// The & means that the vector is passed as a reference,
// which you'll learn more about a bit later
void Adder(std::vector<std::string>& names);
void Remover(std::vector<std::string>& names);
void Printer(std::vector<std::string>& names);

#endif

