#include "aircraft.hpp"
#include <sstream>
//TODO: implement Aircraft's members

    /* constructor
     * Initializes the corresponing members from the parameters.
    */
    Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed) : Vehicle(register_number, owner){
        model_ = model;
        wingspan_ = wingspan;
        cruise_speed_ = cruise_speed;
    }
    
    /* Write
     * Writes the vehicle to the stream given as a parameter in the serialized format.
     * Format for AirCraft:
A;<register number>;<owner>;<model>;<wingspan>;<cruise_speed>\n
    */
    void Aircraft::Write(std::ostream& stream){
        stream << "A;" << this->GetRegisterNumber() << ";" << this->GetOwner() << ";" << model_ << ";" << wingspan_ << ";" << cruise_speed_ << "\n";
    }
    
    /* Print
     * Writes the vehicle to the standard output in the serialized format (See Write).
    */
    void Aircraft::Print(){
        std::cout <<  "A;" << this->GetRegisterNumber() << ";" << this->GetOwner() << ";" << model_ << ";" << wingspan_ << ";" << cruise_speed_ << std::endl;
    }
    
    /* Read
     * Reads an Aircraft from the stream given as parameter, assuming that the vehicle
     * is stored in the serialized format (See Write) and starts immediately from 
     * the current position of the stream.
     * If the vehicle type (the first character) is wrong, returns NULL.
     * If the read was succesful, returns a pointer to a new Aircraft contructed with 
     * the data read. 
    */
    Aircraft* Aircraft::Read(std::istream& stream){
        std::string type, register_numberB, ownerB, modelB;
        double wingspanB; 
        unsigned int cruise_speedB;
        
        std::string info;
        std::string temp;
        getline(stream, info);
        std::stringstream ss(info);
    // Check that reading succeeded
      getline(ss, type,';');
      getline(ss,register_numberB,';');
      getline(ss,ownerB,';');
      getline(ss, modelB,';');
      ss >> wingspanB;
      getline(ss, temp,';');
      ss >> cruise_speedB;
    if (type == "A") {
    
        Aircraft* aircraftPtr = new Aircraft(register_numberB, ownerB, modelB, wingspanB, cruise_speedB);
      
        return aircraftPtr;
    } else {
        return NULL;
    }

    }

