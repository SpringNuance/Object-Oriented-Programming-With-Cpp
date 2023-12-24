#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
//TODO: implement Register's members

    /* destructor
     * Does what destructors should.
    */
    Register::~Register() {
        for (auto it: vehicles_){
            delete it;
        }
    }
    
    /* Add
     * Adds the parameter to the vehicle vector
    */
    void Register::Add(Vehicle* v) {
        vehicles_.push_back(v);
    }
    
    /* Save
     * Saves the vehicles to the file named by the parameter with each vehicle on its
     * own line in the serialized format.
    */
    void Register::Save(const std::string& filename) const {
        std::ofstream os(filename);
        for (auto vehicle: vehicles_){
            vehicle->Write(os);
        }
    }
    
    /* ReadLine
     * Reads a vehicle from the stream given as a parameter assuming a serialized format, and 
     * adds it to the register. Reads a whole line from the stream whether or not constructing 
     * the vehicle was succesful.
     * Returns true if a vehicle was added, false otherwise.
    */
    bool Register::ReadLine(std::istream& stream){
        std::string type, string1, string2, string3, temp;
        double double1; unsigned int double2;
        getline(stream, type,';');
        getline(stream, string1,';');
        getline(stream, string2,';');
        getline(stream, string3,';');
        stream >> double1;
        getline(stream, temp,';');
        stream >> double2;
        getline(stream, temp);
        if (stream){
            if (type == "A"){
                Aircraft* air = new Aircraft(string1, string2, string3, double1, double2);
                vehicles_.push_back(air);
                return true;
            } else if (type == "B"){
                Boat* boat = new Boat(string1, string2, string3, double1, (double)double2);
                vehicles_.push_back(boat);
                return true;
            } else return false;
            
        } return false;

    }
    
    /* Load
     * Reads all vehicles from a file and adds them to the register.
     * Each vehicle is on a different line. On an error the line is discarded and reading is
     * continued from the next line.
     * Returns the number of vehicles added.
     * If file opening fails, the return value should be -1.
    */
    int Register::Load(const std::string& filename){
        int count = 0;
        std::ifstream is(filename);
        if (! is.is_open()) return -1;
        std::string info;
        std::string temp;
        while (getline(is, info)){
            std::stringstream ss(info);
            if (info[0] == 'A'){
                Aircraft * air = Aircraft::Read(ss);
                vehicles_.push_back(air);
                count++;
            } else if (info[0] == 'B'){
                Boat * boat = Boat::Read(ss);
                vehicles_.push_back(boat);
                count++;
            } 
        }
        return count;
    }
    
    /* Print
     * Prints all the vehicles in the register to the standard output each on a different line
     * in the serialized format.
    */
    void Register::Print(){
        for (auto vehicle: vehicles_){
            vehicle->Print();
        }
    }
    
    /* Size
     * Returns the number of vehicles in the register.
    */
    size_t Register::Size() const{
        return vehicles_.size();
    }

