#include <iostream>
#include "string_printer.hpp"

/* Add include guards here */

/* TODO: class StandardPrinter
 * ------------
 * Description:
 * A minimal StringPrinter implementation with no special functionality.
 * ------------
 * Functions:
 * A constructor that takes a single parameter:
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * StandardPrinter prints a string like one normally would but with a 
 * newline at the end. For the string "like this":
like this\n
*/

class StandardPrinter : public StringPrinter {
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    StandardPrinter(std::ostream &os = std::cout) : StringPrinter(os) { }
    /* Copy this object */
    StandardPrinter* Clone() const {
        return new StandardPrinter(os_);
    }
    StandardPrinter& operator()(const std::string& str) {
        /* os_ is a protected member of the base class StringPrinter */
        os_ << str << std::endl;
        return *this;
    }
    
};