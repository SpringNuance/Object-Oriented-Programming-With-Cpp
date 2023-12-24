#ifndef AALTO_ELEC_CPP_TROLL_CLASS
#define AALTO_ELEC_CPP_TROLL_CLASS

#include "creature.hpp"

class Troll : public Creature {
public:
     Troll(const std::string& name, int hitpoints);
};

#endif