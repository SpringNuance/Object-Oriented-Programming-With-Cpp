#include "boat.hpp"
#include <sstream>
//TODO: implement Boat's members


    /* constructor
     * Initializes the corresponing members from the parameters.
    */
    Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power) : Vehicle(register_number, owner){
        name_ = name;
        draft_ = draft;
        power_ = power;
    }
    
    /* Write
     * Writes the vehicle to the stream given as a parameter in the serialized format.
     * Format for Car:
B;<register number>;<owner>;<name>;<draft>;<power>\n
    */
    void Boat::Write(std::ostream& stream){
       stream << "B;" << this->GetRegisterNumber() << ";" << this->GetOwner() << ";" << name_ << ";" << draft_ << ";" << power_ << "\n";
    }
    
    /* Print
     * Writes the vehicle to the standard output in the serialized format (See Write).
    */
    void Boat::Print(){
       std::cout << "B;" << this->GetRegisterNumber() << ";" << this->GetOwner() << ";" << name_ << ";" << draft_ << ";" << power_ << std::endl;
    }
    
    /* Read
     * Reads a Boat from the stream given as parameter, assuming that the vehicle
     * is stored in the serialized format (See Write) and starts immediately from 
     * the current position of the stream.
     * If the vehicle type (the first character) is wrong, returns NULL.
     * If the read was succesful, returns a pointer to a new Boat contructed with 
     * the data read. 
    */
    Boat* Boat::Read(std::istream& stream){
        std::string type, register_numberB, ownerB, nameB;
        double draftB, powerB;
            
        std::string info;
        std::string temp;
        getline(stream, info);
        std::stringstream ss(info);
    // Check that reading succeeded
      getline(ss, type,';');
      getline(ss,register_numberB,';');
      getline(ss,ownerB,';');
      getline(ss, nameB,';');
      ss >> draftB;
      getline(ss, temp,';');
      ss >> powerB;
    if (type == "B") {
    
        Boat* boatPtr = new Boat(register_numberB, ownerB, nameB, draftB, powerB);
      
        return boatPtr;
    } else {
        return NULL;
    }
}


