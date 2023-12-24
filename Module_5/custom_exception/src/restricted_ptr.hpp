/* Add include guards here */

/* 
 * Copy your implementation from the last round here (or wait for
 * the example answer to come out and copy that) and wrap it inside a 
 * WeirdMemoryAllocator namespace.
 * 
 * Changes to the class:
 * 
 * Add a new member string to store the use of the RestrictedPtr 
 * and add a new string parameter, which is the use of the pointer, to the 
 * constructor that originally only takes a pointer. Remember to modify
 * copying to also copy the use. If the pointer is automatically set to 
 * a nullptr (i.e. not given in the constructor), the use is "nullptr".
 * 
 * The copy constructor and assigment operators should throw a RestrictedCopyException 
 * if the operations fail (as they in some cases should). When the copying
 * fails, only the exception should be thrown and no changes should be made
 * to the existing pointer.
 * 
 * The GetData function should throw a RestrictedNullException with the use
 * of the RestrictedPtr given to it if the pointer is null.
 * 
 * The class shouldn't leak any memory.
*/

#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include "restricted_ptr_ex.hpp"
#include <string>

namespace WeirdMemoryAllocator {
template <typename T>
class RestrictedPtr {
public: 
    // Default constructor
    RestrictedPtr() {
        item = nullptr;
        ptrUse = "nullptr";
        refCounter = new restrictedRefCounter();
    };
    
    // Constructor with a raw pointer
    RestrictedPtr(T *item_, std::string use){ 
        item = item_;
        ptrUse = use;
        refCounter = new restrictedRefCounter();
    };

    // Destructor
    ~RestrictedPtr() {
        if (refCounter->getCounter() > 0) {
            refCounter->DecrementCount();
            if (refCounter->getCounter() == 0){
                if (refCounter != nullptr){
                    delete refCounter;
                    refCounter = nullptr;
                }
                if (item != nullptr) {
                    delete item;
                    item = nullptr;
                }
            }
        }
    };
    
    // Copy constructor
    RestrictedPtr(RestrictedPtr &pointer){
        if (pointer.GetRefCount() >= 3){
            throw RestrictedCopyException(pointer.GetPtrUse());
        } else {
            item = pointer.GetPointer();
            refCounter = pointer.GetRRC(); // get reference ref counter
            ptrUse = pointer.ptrUse;
            refCounter->IncrementCount();
        }
    }
    
    // Assignment operator
    // A = B
    RestrictedPtr& operator=(RestrictedPtr &pointer){
        if (pointer.GetRefCount() >= 3){
            throw RestrictedCopyException(pointer.GetPtrUse());
        } else {
            delete item;
            delete refCounter;
            item = pointer.GetPointer();
            refCounter = pointer.GetRRC();
            refCounter->IncrementCount();
            ptrUse = pointer.GetPtrUse();
            return *this;
        }     
    } 

    // GetData, GetPointer, GetRefCount
    T GetData(){ 
        if (item == nullptr){
           throw RestrictedNullException(ptrUse);
        } else return *item ;
    };
    T* GetPointer(){ return item; };
    int GetRefCount(){ return refCounter->getCounter();};
    std::string GetPtrUse() { return ptrUse; };
    restrictedRefCounter* GetRRC(){ return refCounter; }

private:
   restrictedRefCounter* refCounter;
   std::string ptrUse;
   T* item;
};

}
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