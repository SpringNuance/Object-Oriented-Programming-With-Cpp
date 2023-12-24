#pragma once

#include <iostream>
#include "bird.hpp"
#include <stdexcept>

/*
 * If somebody tries to copy an instance of this class,
 * the compilation must fail i.e. TODO: disallow copying
 */
class Aviary {
public:
    Aviary() {}

    /* TODO: method Add
     * Arguments: A pointer to bird.
     * Description: Adds the given bird to the aviary.
     *  If the pointer is NULL, std::logic_error is thrown.
     * Returns: Nothing
     * 
     * When a bird is added to the aviary, it's ownership
     * is transferred. When the aviary is destroyed, all
     * the birds are destroyed too.
     */

    void Add(Bird* bird);
        
    /* TODO: method SpeakAll
     * Arguments: A reference to ostream.
     * Description: Calls the Speak method with the given parameter  
     *  on all birds in the aviary
     * Returns: Nothing
     * 
     * Does not modify the object, thus it should be const
     */

    void SpeakAll(std::ostream& os) const;
    
    // Create a new type alias sizeType

    // Returns how many birds there are in the aviary.
    /* TODO: method Size
     * Arguments: None.
     * Description: Returns the number of birds in the aviary
     * Returns: size_t
     * 
     * Does not modify the object, thus it should be const
     */

    size_t Size() const;
    
    /* TODO: const and non-const versions of the indexing operator []
     * Arguments: size_t
     * Description: Returns a pointer to the bird at the index given as a parameter.
     *  If the index is out of bounds, std::out_of_range is thrown.
     * Returns: const Bird* for the const version and
     *  Bird* for the non-const version.
    */

    const Bird* operator [](size_t index) const;
    
    Bird* operator [](size_t index);

    /* TODO: destructor */
    ~Aviary() {
        for (auto it : birds) {
            delete it;
        }
    }

    private:
        std::vector<Bird*> birds;
        Aviary(const Aviary&);
        Aviary& operator=(const Aviary& aviary);

};
