#include "dragon.hpp"

Dragon::Dragon(const std::string& name, int hitpoints) : Creature(name, "Dragon", hitpoints) {}

/*

Cat::Cat(const std::string& name, const double& weight) : Mammal(weight) { 
    name_ = name;
}

std::string Cat::GetName(){
    return name_;
}

std::string Cat::MakeSound(){
    return "Meow";
}

*/