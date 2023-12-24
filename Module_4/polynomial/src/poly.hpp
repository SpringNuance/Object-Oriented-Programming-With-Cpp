#ifndef ELEC_AS_CPP_POLY
#define ELEC_AS_CPP_POLY

#include <iosfwd>
#include <map>
#include <iostream>
#include <sstream>

/* Polynomial is a mathematical expression consisting of terms summed to each-other. 
 * In this exercise you will implement class Poly, holding a single polynomial 
 * where each term is of form <mul>x<exp>. 
 * For example, the parabola 4x²+2x+7 would be stored in the Poly object as 
 * std::map<int, int> of pairs of exponent and multiplier: (0, 7), (1, 2), (2, 4).
 * 
 * Before starting, make yourself familiar with operator overloading. 
 * Then implement for your class the following accessors and operators, 
 * and test your implementation with the given main.
 *
 * 
 * Implement:
 *
 * Negation operator (unary operator-) that changes the sign of the multiplier of each term.
 *
 * Binary (two-operand) operators +, -, += and -= that do the corresponding mathematical operations 
 * (adding/subtracting the multipliers termwise)
 *
 * operator<< and operator>>, using the formats described below.
 *
 * A few operators have been implemented for you in poly.hpp and poly.cpp. 
 * Add the missing operators but do not modify the existing ones. 
 *
 *
 * Stream I/O format
 *
 * A simplified format where each term is of format <mul>x<exp> is used. 
 * Between each term there must be a plus or a minus sign depending on the sign of the multiplier of the next term. 
 * For example, 4x²+2x+7 would be written 4x2+2x1+7x0 and -7x^-2 would be written as -7x-2.
 *
 * The output operator must normalize the output by printing the terms with descending order (highest exponent first) 
 * and by omitting all terms where the multiplier is zero. 
 * Nothing is printed if there are no non-zero terms in the polynomial.
 * 
 * The input operator should read the similar format described above and create polynomials based on it.
 * This can be achieved by first reading the input as a string and then using a string stream to parse the
 * multiplier and the exponent from the string stream with the >> operator. 
 *
 * 
 * Ordering
 *
 * In this exercise the degree (the exponent of the first non-zero term) of the polynomial alone determines the order for the comparison operators. 
 * Multipliers or other terms have no effect. E.g. 3x² is considered equal to 1000x²+123x and x³ is considered greater than any of the two others. 
 * An empty polynomial is less than any non-empty polynomial.
 */

/* Recommended order for implementing:
 * 1. Unary operator-
 * 2. Binary operators: operator+= & operator+
 * 3. operator-= & operator-
 * 4. Operators for comparisons.
 * 5. Input & output operators.
 */

class Poly {
public:
    /* Use these to traverse map in the order you want.
     * Reverse iterators might be useful when you need to start from the highest exponent.
     * for more information see http://www.cplusplus.com/reference/map/map/
     */

    // Normal iterators (const and non-const)
    std::map<int, int>::const_iterator cbegin() const { return values_.cbegin(); }
    std::map<int, int>::const_iterator cend() const { return values_.cend(); }
    std::map<int, int>::const_iterator begin() const { return values_.begin(); }
    std::map<int, int>::const_iterator end() const { return values_.end(); }
    std::map<int, int>::iterator begin() { return values_.begin(); }
    std::map<int, int>::iterator end() { return values_.end(); }
    
    // Reverse iterators (const and non-const)
    std::reverse_iterator<std::map<int, int>::const_iterator> crbegin() const { return values_.crbegin(); }
    std::reverse_iterator<std::map<int, int>::const_iterator> crend() const { return values_.crend(); }
    std::reverse_iterator<std::map<int, int>::const_iterator> rbegin() const { return values_.rbegin(); }
    std::reverse_iterator<std::map<int, int>::const_iterator> rend() const { return values_.rend(); }
    std::reverse_iterator<std::map<int, int>::iterator> rbegin() { return values_.rbegin(); }
    std::reverse_iterator<std::map<int, int>::iterator> rend() { return values_.rend(); }
    
    int operator[](int exp) const;
    int& operator[](int exp) { return values_[exp]; }
    
    // TODO: implement the following operators in poly.cpp
    Poly& operator+=(const Poly& b);
    Poly& operator-=(const Poly& b);
private:
    std::map<int, int> values_;
};

// TODO: implement all of the following in poly.cpp
std::istream& operator>>(std::istream& is, Poly& p);
std::ostream& operator<<(std::ostream& os, const Poly& p);

Poly operator+(const Poly& a, const Poly& b);
Poly operator-(const Poly& a, const Poly& b);
Poly operator-(const Poly& p);

bool operator<(const Poly& a, const Poly& b);
bool operator==(const Poly& a, const Poly& b);
bool operator>(const Poly& a, const Poly& b);
bool operator!=(const Poly& a, const Poly& b);

#endif

