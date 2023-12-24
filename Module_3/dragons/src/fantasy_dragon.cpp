#include "fantasy_dragon.hpp"
    
    /*
     * Eat: an override of Dragon's Eat.
 *  FantasyDragons only eat Food whose type is either People or PeopleFood. 
 *  Each eaten Food item increases the dragon's size by one.
 * 
 *  The food that the dragon eats is removed from the parameter food list and
 *  each time the dragon feasts upon something you should print information of
 *  the Food that is being eaten to standard output in the following format:
Fantasy dragon ate: <Food's name>\n
 *
 *  The food should be eaten in the order from the list's beginning to end.
    */
void FantasyDragon::Eat(std::list<Food>& foods) {
        auto ptr = foods.begin();
        while (ptr != foods.end()){
            if (ptr->type == PeopleFood || ptr->type == People){
                std::cout << "Fantasy dragon ate: " << ptr->name << std::endl;
                size++;
                ptr = foods.erase(ptr);
            } else ptr++;
        }
    }


/* 

 * Hoard: an override of Dragon's Hoard.
 *  FantasyDragons hoard only Treasures whose type is Jewellery. Each hoarded 
 *  treasure is added to the dragon's treasure list and is removed from 
 *  the parameter treasure list.
 * 
 *  Each time the FantasyDragon hoards an item you should print information about the hoarded
 *  item to standard output in the following format:
Fantasy dragon received: <Treasure's name>\n
 *
 *  The treasures should be received in the order from the list's beginning to end.
 * ------------
 * Other:
 * Public members of Dragon should be public in FantasyDragon as well.
 */
void FantasyDragon::Hoard(std::list<Treasure>& newTreasures){
auto ptr = newTreasures.begin();
        while (ptr != newTreasures.end()){
            if (ptr->type == Jewellery){
                std::cout << "Fantasy dragon received: " << ptr->name << std::endl;
                treasures.push_back(*ptr);
                ptr = newTreasures.erase(ptr);
            } else {
               ++ptr;
            }
        }
}