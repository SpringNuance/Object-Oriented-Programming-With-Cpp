
#include <iostream>

/* Add include guards here */

/* Class: Triple
 * -------------
 * The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
template<typename A, typename B, typename C> 
class Triple {
public: 
    Triple(){};
    Triple(const A& v1_, const B& v2_, const C& v3_): v1(v1_), v2(v2_), v3(v3_){};
    /* Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */
    const A& First() const { return v1; }
    const B& Second() const { return v2; }
    const C& Third() const { return v3; }
    // copy constructor 
    Triple(const Triple &triple): v1(triple.v1), v2(triple.v2), v3(triple.v3) { 
    } 
    
    // assignment operation
    Triple operator=(const Triple &triple){
        v1 = triple.v1;
       v2 = triple.v2;
       v3 = triple.v3;
        return *this;
    } 
    
    /*
    friend bool operator==(const Triple & triple1, const Triple & triple2){
        return (triple1.First() == triple2.First() && triple1.Second() == triple2.Second() && triple1.Third() == triple2.Third());
    }

    friend bool operator!=(const Triple & triple1, const Triple & triple2){
        return (triple1.First() != triple2.First() && triple1.Second() != triple2.Second() && triple1.Third() != triple2.Third());
    }
    */


private:
    A v1;
    B v2;
    C v3;
};


template<typename A, typename B, typename C> 
bool IsHomogenous(const Triple<A,B,C> & triple){
  return false;
}

template<typename A> 
bool IsHomogenous(const Triple<A,A,A> & triple){
  return true;
}

template<typename A, typename B, typename C> 
bool operator==(const Triple<A,B,C> & triple1, const Triple<A,B,C> & triple2){
    return (triple1.First() == triple2.First() && triple1.Second() == triple2.Second() && triple1.Third() == triple2.Third());
}

template<typename A, typename B, typename C> 
bool operator!=(const Triple<A,B,C> & triple1, const Triple<A,B,C> & triple2){
    return (triple1.First() != triple2.First() && triple1.Second() != triple2.Second() && triple1.Third() != triple2.Third());
}

template<typename A, typename B, typename C>     
std::ostream& operator<<(std::ostream& os, const Triple<A,B,C> & triple){
    os << "[" << triple.First() << ", " << triple.Second() << ", " << triple.Third() << "]";
    return os;
}

     /*
bool operator==(const Triple & triple2){
    return (v1 == triple2.First() && v2 == triple2.Second() && v3 == triple2.Third());
}

bool operator!=(const Triple & triple2){
    return (v1 != triple2.First() && v2 != triple2.Second() && v3 != triple2.Third());
}*/



/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */


/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

/* Remember the endif here to close the header guards */

