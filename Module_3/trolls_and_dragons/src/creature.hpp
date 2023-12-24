#ifndef AALTO_ELEC_CPP_CREATURE_CLASS
#define AALTO_ELEC_CPP_CREATURE_CLASS

#include <string>
#include <vector>
#include <iostream>

class Creature {
public:
	Creature(const std::string& name, const std::string& type, int hitpoints);

	const std::string& GetName() const;
	const std::string& GetType() const;
	int GetHitPoints() const;

private:
	std::string name_;
	const std::string type_;
	int hitpoints_;
};

// Define the '<<' operator here
std::ostream& operator<<(std::ostream& out, const Creature& crea);

#endif