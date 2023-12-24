#include "geomvector.hpp"

// Implement operators here


GeomVector GeomVector::operator+(const GeomVector& a) {
    return GeomVector(a.x_ + x_, a.y_ + y_, a.z_ + z_);
}

GeomVector operator*(double a, const GeomVector& b) {
    return GeomVector(a * b.x_, a * b.y_, a * b.z_);
}

std::ostream &operator<<(std::ostream& out, const GeomVector& a) {
    out << "(" << a.x_ << ", " << a.y_ << ", " << a.z_ << ")";
    return out;
}

double GeomVector::Length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

GeomVector GeomVector::operator/(double num){
    return GeomVector(this->x_/num, this->y_/num, this->z_/num);
}

bool GeomVector::operator>(const GeomVector& a){
   return this->Length() > a.Length();
}

bool GeomVector::operator<(const GeomVector& a){
   return this->Length() < a.Length();
}

bool GeomVector::operator==(const GeomVector& a){
   return (this->x_ == a.x_ && this->y_ == a.y_ && this->z_ == a.z_); 
}

bool GeomVector::operator!=(const GeomVector& a){
   return (this->x_ != a.x_ || this->y_ != a.y_ || this->z_ != a.z_);
}