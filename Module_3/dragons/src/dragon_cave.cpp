#include "dragon_cave.hpp"


// Define DragonCave's methods here

/*
 GetDragons: the function returns a const reference to the DragonCave's
 * list of Dragon pointers. The function takes no parameters and does not change 
 * the DragonCave's state, i.e. the function should be const.
 *
 * Accommodate: takes a Dragon pointer as a parameter and adds it to the end of
 * the DragonCave's Dragon pointer list. The function returns nothing.
 * 
 * Evict: takes a Dragon's name as a const string reference as a parameter.
 * Tries to find a dragon with a matching name from the DragonCaves Dragon pointer
 * list. Erases the first Dragon pointer with a matching name from the list. If
 * there is no Dragon with a matching name in the list, the function does nothing.
 * Note that the function only erases the pointer from the list, but DOES NOT delete
 * the Dragon object. The function returns nothing.*/

const std::list<Dragon*>& DragonCave::GetDragons() const {
    return dragons;
}

void DragonCave::Accommodate(Dragon* dragon) {
    dragons.push_back(dragon);
}

void DragonCave::Evict(std::string dragonName){
    auto ptr = dragons.begin();
    while (ptr != dragons.end()){
        if ((*(*ptr)).GetName() == dragonName){
            dragons.erase(ptr);
            break;
        }
        ptr++;
    }
}

/* TODO: operator <<
 * ------------
 * Description:
 * An overloaded << stream operator for printing DragonCaves to parameter ostreams.
 * The DragonCave should be printed to the parameter ostream in the following format:
DragonCave dwellers:\n
\n
<First Dragon in the dragons list>\n
<Second Dragon in the dragons list>\n
...
<Last Dragon in the dragons list>
 *
 * NOTE: The dragons in the dragon list are printed in the same format as the overloaded
 *       << stream operator for Dragons prints them. Also note that there is an additional
 *       end line character after each dragon except for the last one.
 * ------------
 * Parameters:
 * - the output stream to which the information is printed (ostream).
 * - the DragonCave whose information should be printed (const DragonCave&).
 * ------------
 * Returns:
 * The parameter output stream.
 */


std::ostream& operator<<(std::ostream& out, const DragonCave& dragonCave){
     out << "DragonCave dwellers:\n";
     out << "\n";
     auto ptr = dragonCave.GetDragons().begin();
     while (ptr != std::prev(dragonCave.GetDragons().end())){
           out << **ptr << "\n";
           ptr++;
     }
     out << **ptr;
     return out;
}

/*
std::ostream& Dragon::operator<<(std::ostream& out, const Dragon& dragon){
    out << "Dragon named: " << dragon.GetName() << ", age: " << dragon.GetAge() << ", size: " << dragon.GetSize() <<"\n ";
    out << "Treasures:\n"
    for (auto treasure : dragon.treasures){
        out << treasure.name << "\n";
    }
    return out;
}
*/