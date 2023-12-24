#include "pokemon.hpp"
#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <algorithm>

    /* constuctor
    * initializes the collection to contain all the pokemons from the two 
    * collections given as parameters and removes all duplicates, takes the following parameters:
    *  - collection: a PokemonCollection
    *  - collection2: a PokemonCollection
    * Hint: sorting at some point would probably help
    * 
    * All the other functions must get full points before this is tested.
    */


    PokemonCollection::PokemonCollection(PokemonCollection collection, PokemonCollection collection2){
      pokemons_ = collection.pokemons_;
      std::copy(collection2.pokemons_.begin(), collection2.pokemons_.end(), std::back_inserter(pokemons_));
      SortByName();
      pokemons_.unique();
    }
    
    /* Add:
    * adds a pokemon to the end of the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id, 
    */ 
    void PokemonCollection::Add(const std::string& name, size_t id){
       auto pokemon = std::pair<std::string, size_t>(name, id);
       pokemons_.push_back(pokemon);
    }
    
    /* Remove:
    * removes a pokemon to the collection, takes the following parameters:
    *  - the pokemon's name, 
    *  - the pokemon's id
    * returns true if the pokemon was found and removed, false otherwise
    * 
    *   void Customer::ReturnBook(Book& book){
     unsigned int i = 0;
     while (i < loaned_books_.size()){
         if (loaned_books_[i].GetName() == book.GetName()) {
             loaned_books_.erase(loaned_books_.begin() + i);
             book.Restore();
             return;
         }
         i++;
     }
   };
    */ 
    bool PokemonCollection::Remove(const std::string& name, size_t id){

       auto ptr = pokemons_.begin();
       while (ptr != pokemons_.end()){
           if ((*ptr).first == name && (*ptr).second == id){
               pokemons_.erase(ptr);
               return true;
           }
           ptr++;
       }
       return false;
    }
    
    /* Print:
    * Prints the collection to the standard output stream. 
    * The format of the print should be as below: 
id: <id>, name: <name>\n
id: <id>, name: <name>\n
    */ 
    void PokemonCollection::Print() const {
       for (auto pokemon : pokemons_){
           std::cout << "id: "<< pokemon.second << ", name: " << pokemon.first << std::endl;
       }
    }
    
    
    bool sortName(const std::pair<std::string, size_t>& pok1, const std::pair<std::string, size_t>& pok2) {
       if (pok1.first < pok2.first) {
           return true;
       } else if (pok1.first > pok2.first) {
           return false;
       } else {
           if (pok1.second <= pok2.second) {
               return true;
           } else return false;
       }
    }



    /* SortByName:
    * sorts the collection by name.
    * If two names are equal, their order is determined by their ids
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */ 
    void PokemonCollection::SortByName(){
        pokemons_.sort(sortName);
    }
    
    /* SortById:
    * sorts the collection by id
    * If two ids are equal, their order is determined by their names
    * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
    * However a valid and easy solution does exist!
    */ 

    bool sortId(const std::pair<std::string, size_t>& pok1, const std::pair<std::string, size_t>& pok2) {
       if (pok1.second < pok2.second) {
           return true;
       } else if (pok1.second > pok2.second) {
           return false;
       } else {
           if (pok1.first <= pok2.first) {
               return true;
           } else return false;
       }
    }

    void PokemonCollection::SortById(){
        pokemons_.sort(sortId);
    }

