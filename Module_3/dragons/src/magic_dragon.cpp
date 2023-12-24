#include "magic_dragon.hpp"

// Define MagicDragon's methods here

  
void MagicDragon::Eat(std::list<Food>& foods) {
        auto ptr = foods.begin();
        while (ptr != foods.end()){
            if (ptr->type == Herbs){
                std::cout << "Magic dragon ate: " << ptr->name << std::endl;
                size++;
                ptr = foods.erase(ptr);
            } else ptr++;
        }
    }

void MagicDragon::Hoard(std::list<Treasure>& newTreasures){
auto ptr = newTreasures.begin();
        while (ptr != newTreasures.end()){
            if (ptr->type == Potions){
                std::cout << "Magic dragon received: " << ptr->name << std::endl;
                treasures.push_back(*ptr);
                ptr = newTreasures.erase(ptr);
            } else ptr++;
        }
}