#include "list.hpp"
#include <iostream>
#include <algorithm>

// Implement the functions here
/** Read all lines from the stream into the list. Newline characters are not
 * stored in the list. Returns the stream. **/
std::istream& GetLines(std::istream& is, std::list<std::string>& list){
  list.clear();

  std::string line;
  while (!is.eof()) {
    line.clear();
    std::getline(is, line);
    list.push_back(line);
  }
  list.pop_back();
  return is;
}

/** Print the list, with a newline after each entry. **/
void Print(const std::list<std::string>& list){
  for (std::list<std::string>::const_iterator ptr = list.begin(); ptr != list.end(); ptr++){
    std::cout << *ptr << std::endl;
  }
}


/** Sort the list and remove all duplicate entries. **/
void SortAndUnique(std::list<std::string>& list){
    list.sort();
    list.unique();
}
