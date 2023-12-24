#include <iostream>
#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"

int main(void) {
    Register r;
    r.Load("readtester.txt");
    r.Print();
    r.Add(new Aircraft("G_BOAC", "British Airways", "Concorde SST", 80.8, 2000));
    r.Add(new Aircraft("RU-123", "Russian Federation", "MiG-21", 80.8, 1600));
    r.Add(new Boat("FI123", "Pekka Purjehtija", "Mariella", 0.0, 1.8));
    r.Save("test2.txt");
    r.Print();
}
