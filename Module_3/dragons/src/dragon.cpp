#include "dragon.hpp"

/*
 * The constructor takes the Dragon's name (const std::string&), age (size_t) and 
 * size (size_t) as a parameter and intializes them to the parameter values.
*/
Dragon::Dragon(const std::string& name, size_t age, size_t size) {
    this->name = name; 
    this->age = age;
    this->size = size;
 }

  /*
 * Destructor: Think about how it should be implemented!
  */


const std::string& Dragon::GetName() const{
    return name;
}
size_t Dragon::GetAge() const {
    return age;
}
size_t Dragon::GetSize() const {
    return size;
}
const std::list<Treasure>& Dragon::GetTreasures() const {
    return treasures;
}

std::ostream& operator<<(std::ostream& out, const Dragon& dragon){
    out << "Dragon named: " << dragon.GetName() << ", age: " << dragon.GetAge() << ", size: " << dragon.GetSize() << std::endl;
    out << "Treasures:" << std::endl;
    for (auto treasure : dragon.GetTreasures()){
        out << treasure.name << std::endl;
    }
    return out;
}