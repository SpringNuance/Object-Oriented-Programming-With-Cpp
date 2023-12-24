#include "rectangle.hpp"

#include <iostream>

// Write you function here and test it with the main.

void Rectangle() {
    double w, h;
    std::cout << "Please enter width and height" << std::endl;
    std::cin >> w >> h;
    // Similar thing
    // std::cin >> w
    // std::cin >> h
    double area = w * h;
    double circum = 2 * (w + h);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circum << std::endl;
}

