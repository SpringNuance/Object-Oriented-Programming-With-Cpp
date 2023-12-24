#include <iostream>
#include "string_printer.hpp"

/* Add include guards here */

/* TODO: class DiagonalPrinter
 * ------------
 * Description:
 * A class that is used to print strings diagonally (see below).
 * The class inherits (public inheritance) class StringPrinter.
 * ------------
 * Functions:
 * 
 * A constructor that takes three parameters:
 *  - The first line, which is "" by default, i.e. it is not printed at all
 *  - The last line, which is "" by default, i.e. it is not printed at all either
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * DiagonalPrinter prints a string diagonally. For the string "like this":
<first line>\n
l        \n
 i       \n
  k      \n
   e     \n
         \n
     t   \n
      h  \n
       i \n
        s\n
<last line>\n
 * where <first line> and <last line> are replaced by the strings given in the
 * constructor. If the first line is empty, it is not printed. The same applies
 * to the last line.
 */
class DiagonalPrinter : public StringPrinter {
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    DiagonalPrinter(std::string firstLine_ = "", std::string lastLine_ = "", std::ostream &os = std::cout) : StringPrinter(os) { 
        firstLine = firstLine_;
        lastLine = lastLine_;
    }
    /* Copy this object */
    DiagonalPrinter* Clone() const {
        return new DiagonalPrinter(firstLine, lastLine, os_);
    }
    DiagonalPrinter& operator()(const std::string& str) {
        /* os_ is a protected member of the base class StringPrinter */
        if (!firstLine.empty()) os_ << firstLine << std::endl;
        for (unsigned int i = 0; i < str.length(); i++){
            for (unsigned int j = 0; j < i; j++){
                os_ << " ";
            }
            os_ << str[i];
            for (unsigned int k = i + 1; k < str.length(); k++){
                os_ << " ";
            }
            os_ << std::endl;
        }
        if (!lastLine.empty()) os_ << lastLine << std::endl;
        return *this;
    }
    private:
       std::string firstLine;
       std::string lastLine;
};