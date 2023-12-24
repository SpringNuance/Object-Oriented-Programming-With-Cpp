#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include <string>

template <typename T>
class RestrictedPtr {
public: 
    // Default constructor
    RestrictedPtr() {
        refCounter = new restrictedRefCounter();
    };
    
    // Constructor with a raw pointer
    RestrictedPtr(T *item_){ 
        item = item_;
        refCounter = new restrictedRefCounter();
    };

    // Destructor
    ~RestrictedPtr() {
        (*refCounter).DecrementCount();
        if (refCounter->getCounter() == 0)
        {
            delete refCounter;
            delete item;
        }
    };
    
    // Copy constructor
    RestrictedPtr(RestrictedPtr &pointer){
        if (pointer.GetPointer()){
            if (pointer.GetRefCount() < 3){
                item = pointer.GetPointer();
                refCounter = pointer.GetRRC();
                refCounter->IncrementCount();
            }  else {
                item = nullptr;
                refCounter = new restrictedRefCounter();
            }
        } else {
            refCounter = new restrictedRefCounter();
            item = nullptr;
        }
    }

    RestrictedPtr& operator=(RestrictedPtr &pointer){
        if (pointer.GetPointer()){
            if (pointer.GetRefCount() < 3){
                item = pointer.GetPointer();
                refCounter = pointer.GetRRC();
                refCounter->IncrementCount();
            }  else {
                item = nullptr;
                refCounter = new restrictedRefCounter();
            }
        } else {
            refCounter = new restrictedRefCounter();
            item = nullptr;
        }
        return *this;
    } 

  

    // GetData, GetPointer, GetRefCount
    T GetData(){ return *item ;};
    T* GetPointer(){ return item; };
    int GetRefCount(){ return refCounter->getCounter();};
    restrictedRefCounter* GetRRC(){ return refCounter; }

private:
   restrictedRefCounter* refCounter;
   T* item;
};
/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/

#endif