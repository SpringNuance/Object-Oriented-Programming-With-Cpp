#include "poly.hpp"

#include <sstream>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

// Correct ----------------------------------
Poly& Poly::operator+=(const Poly& b){
    for (auto ptr = b.begin(); ptr != b.end(); ptr++){
       (*this)[ptr->first] += ptr->second;
    }
    return *this;
}

// Correct ----------------------------------
Poly& Poly::operator-=(const Poly& b){
    for (auto ptr = b.begin(); ptr != b.end(); ptr++){
       (*this)[ptr->first] -= ptr->second;
    }
    return *this;
}

// Correct ----------------------------------
std::istream& operator>>(std::istream& is, Poly& p){
    Poly newP;
    p = newP;
    std::string info;
    int key, value;
    std::stringstream ss;
    is >> info;
    ss << info;
    while (ss) {
        ss >> value;
        ss.get();
        ss >> key;
        p[key] = value;
    }
    return is;
}

// Correct ----------------------------------
std::ostream& operator<<(std::ostream& os, const Poly& p){
   auto ptr = p.rbegin();
   if (ptr == p.rend()) return os;
   os << ptr->second << "x" << ptr->first;
   ptr++;
   while (ptr != p.rend()){
       if (ptr->second > 0){
           os << "+" << ptr->second << "x" << ptr->first;
       } else if (ptr->second < 0) {
           os << ptr->second << "x" << ptr->first;
       } 
       ptr++;
   }
   return os;
}

// Correct ----------------------------------
Poly operator+(const Poly& a, const Poly& b){
    auto ptrA = a.begin();
    auto ptrB = b.begin();
    Poly newP;
    while (ptrA != a.end()){
        newP[ptrA->first] = ptrA->second;
        ptrA++;
    }
    while (ptrB != b.end()){
        newP[ptrB->first] += ptrB->second;
        ptrB++;
    }
    return newP;
}

// Correct ----------------------------------
Poly operator-(const Poly& a, const Poly& b){
    auto ptrA = a.begin();
    auto ptrB = b.begin();
    Poly newP;
    while (ptrA != a.end()){
        newP[ptrA->first] = ptrA->second;
        ptrA++;
    }
    while (ptrB != b.end()){
        newP[ptrB->first] -= ptrB->second;
        ptrB++;
    }
    return newP;
}

// Correct ----------------------------------
Poly operator-(const Poly& p){
   Poly newP; 
   auto ptr = p.begin();
   while (ptr != p.end()){
       newP[ptr->first] = -(ptr->second);
       ptr++;
   }
   return newP;
}

// Correct ----------------------------------
bool operator<(const Poly& a, const Poly& b){
    int countA = 0;
    int countB = 0;
    for (auto ptr = a.begin(); ptr != a.end(); ptr++, countA++);
    for (auto ptr = b.begin(); ptr != b.end(); ptr++, countB++);
    return countA < countB;
}

bool operator==(const Poly& a, const Poly& b){
    if (a > b || a < b) return false;
    auto ptrA = a.begin();
    auto ptrB = b.begin();
    while (ptrA != a.end() && ptrB != b.end()){
       if (ptrA->second != ptrB->second) return false;
       ptrA++;
       ptrB++;
    }
    return true;

}


// Correct ----------------------------------
bool operator>(const Poly& a, const Poly& b){
    int countA = 0;
    int countB = 0;
    for (auto ptr = a.begin(); ptr != a.end(); ptr++, countA++);
    for (auto ptr = b.begin(); ptr != b.end(); ptr++, countB++);
    return countA > countB;
}

bool operator!=(const Poly& a, const Poly& b){
    if (a > b || a < b) return true;
    auto ptrA = a.begin();
    auto ptrB = b.begin();
    while (ptrA != a.end() && ptrB != b.end()){
       if (ptrA->second != ptrB->second) return true;
       ptrA++;
       ptrB++;
    }
    return false;
}
