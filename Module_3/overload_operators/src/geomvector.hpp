#ifndef AALTO_ELEC_CPP_GEOMVECTOR_CLASS
#define AALTO_ELEC_CPP_GEOMVECTOR_CLASS

#include <iostream>
#include <cmath>

class GeomVector {
public:
    GeomVector(double x, double y, double z) : x_(x),y_(y),z_(z) { }
    
    // Get GeomVector length
    double Length() const;

    // This is member function of GeomVector
    GeomVector operator+(const GeomVector& a);
    
    // Define operators here
    GeomVector operator/(double num);
    bool operator>(const GeomVector& a);
    bool operator<(const GeomVector& a);
    bool operator==(const GeomVector& a);
    bool operator!=(const GeomVector& a);


    // These are external functions, but have access to private parts,
    // because they are declared as 'friend'.
    friend GeomVector operator*(double a, const GeomVector& b);
    friend std::ostream& operator<<(std::ostream& out,
                    const GeomVector& a);

private:
    double x_,y_,z_;
};

#endif