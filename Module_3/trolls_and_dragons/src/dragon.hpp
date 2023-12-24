#ifndef AALTO_ELEC_CPP_DRAGON_CLASS
#define AALTO_ELEC_CPP_DRAGON_CLASS

#include "creature.hpp"

class Dragon : public Creature {
public:
     Dragon(const std::string& name, int hitpoint);
};

#endif

/*

class Cat : public Mammal {
public:
    Cat(const std::string& name, const double& weight);
    std::string GetName();
    static std::string MakeSound();
private:
    std::string name_;
};

*/