#include "creature.hpp"

Creature::Creature(const std::string& name, const std::string& type, int hitpoints)
    : name_(name), type_(type), hitpoints_(hitpoints) { }

const std::string& Creature::GetName() const { return name_; }
const std::string& Creature::GetType() const { return type_; }
int Creature::GetHitPoints() const { return hitpoints_; }

// Implement the '<<' operator here
std::ostream& operator<<(std::ostream& out, const Creature& crea){
    out << crea.GetType() << " " << crea.GetName() << " with " << crea.GetHitPoints() << " HP";
      return out;
}
