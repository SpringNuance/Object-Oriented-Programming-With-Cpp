#include "dog.hpp"

Dog::Dog(const std::string& name, const double& weight) : Mammal(weight) { 
    name_ = name;
}

std::string Dog::GetName(){
    return name_;
}

std::string Dog::MakeSound(){
    return "Wuff!";
}
