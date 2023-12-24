#ifndef AALTO_ELEC_CPP_DOG_CLASS
#define AALTO_ELEC_CPP_DOG_CLASS

#include <string>

//Definition of simple a class with some errors

class Dog {
public:
    Dog(int age, std::string name);
    
    void SetAge(int age);
    int GetAge();
    void SetName(std::string name);
    std::string GetName();
private:
    int age_;
    std::string name_;
};

#endif

