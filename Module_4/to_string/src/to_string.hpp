#ifndef AALTO_ELEC_CPP_TO_STRING_CLASS
#define AALTO_ELEC_CPP_TO_STRING_CLASS
#include <iostream>


/* As an introduction to templates you will write and specialize a template function 
 * for formatting the contents of a container (string, vector, list, ...) into a string, 
 * assuming that the elements of the container are printable (with the << operator). 
 *
 * This function is called ToString and it returns the container contents in the following format 
 * (assuming a container of strings with three elements: "foo", "bar" and "baz"): 
{ foo, bar, baz }
 * (assuming a container of ints with three elements: 10, -5 and 4): 
{ 10, -5, 4 }
 * When passed a std::string, the function should, instead of returning a list of characters { f, o, o, b, a, r }, 
 * just put double quotes around the string:
"foobar"
 * Additionally, overload the function with a version that, instead of a container, 
 * takes begin and end iterators, and formats the contents in the format specified above for containers 
 * (no special handling for string iterators).
 *
 * Notes:
 * You may assume that std::strings have their regular interface. 
 * For other containers, only use the iterator interface (begin and end functions).
 * Your functions must work with at least bidirectional iterators. Note that such 
 * iterators do not have operators + and - (but they do have ++ and --).
 * If you'd really want to provide printing support for containers, 
 * you should write operator<< for them instead of a ToString function.
 * This would allow printing containers that contain other containers, etc.
 */



template <typename T>
std::string ToString(T& container) {
    std::string word = "{ ";
    for (auto it: container) { 
        word += std::to_string(it);
        word += ", "; 
    }
    word.pop_back();
    word.pop_back();
    word += " }";
    return word;
}

template<>
std::string ToString(std::string& container){
    return "\"" + container + "\"";
} 

template <typename Iter>
std::string ToString(Iter it, Iter end) {
    std::string word = "{ ";
    for (; it != end; ++it) { 
        word += std::to_string(*it);
        word += ", "; 
    }
    word.pop_back();
    word.pop_back();
    word += " }";
    return word;
}

template <>
std::string ToString(std::string::iterator it, std::string::iterator end) {
    std::string word = "{ ";
    for (; it != end; ++it) { 
        word += *it;
        word += ", "; 
    }
    word.pop_back();
    word.pop_back();
    word += " }";
    return word;
}




#endif