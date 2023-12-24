#include "cat.hpp"

Cat::Cat(const std::string& name, const double& weight) : Mammal(weight) { 
    name_ = name;
}

std::string Cat::GetName(){
    return name_;
}

std::string Cat::MakeSound(){
    return "Meow";
}
