#include "person.hpp"
#include <string>

// define your Person class' functions here

Person::Person(std::string Name, int birthyear) 
  : Name_(Name), birthyear_(birthyear) {
  }

const std::string& Person::GetName() {
    return Name_;
}

int Person::GetAge(int age) {
    return (age - birthyear_) ;
}

