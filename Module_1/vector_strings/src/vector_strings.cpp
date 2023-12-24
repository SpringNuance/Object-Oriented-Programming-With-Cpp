#include "vector_strings.hpp"

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Adder(std::vector<std::string>& names) {
    std::string name;
    std::cout << "Enter a name:" << std::endl;
    std::cin >> name;
    names.push_back(name);
    std::cout << "Number of names in the vector:\n" << names.size() << std::endl;
}

void Printer(std::vector<std::string>& names) {
    for (unsigned int i = 0; i < names.size(); i++){
        std::cout << names[i] << std::endl;
    }
}

void Remover(std::vector<std::string>& names) {
    std::string removedName = names.back();
    names.pop_back();
    std::cout << "Removing the last element:\n" << removedName << std::endl;
}

void CMDReader() {
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
    std::vector<std::string> names;
    int check = 1;
    while (check){
        std::string command;
        std::cout << "Enter a command:" << std::endl;
        std::cin >> command;
        if (command == "ADD"){
          Adder(names);
        } else if (command == "PRINT"){
            Printer(names);
        } else if (command == "REMOVE"){
            Remover(names);
        } else if (command == "QUIT"){
            check = 0;
        } else {
          std::cout << "Unknown command" << std::endl;
        }
    }
}

