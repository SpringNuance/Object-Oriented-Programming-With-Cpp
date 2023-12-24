#include "dog_class.hpp"

//Definitions of class functions with some errors


Dog::Dog(int a, std::string n) { 
    age_ = a; 
    name_ = n; 
}


void Dog::SetAge(int a) {
    age_ = a; 
}


int Dog::GetAge() {
    return age_; 
}


void Dog::SetName(std::string n) {
    name_ = n; 
}


std::string Dog::GetName() {
    return name_; 
}


