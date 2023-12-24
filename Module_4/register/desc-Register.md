**Objective:** Practicing I/O together with class inheritance and
polymorphism.

You will need to implement a vehicle register. You will also implement a
way to  serialize the instances stored in the register and output the
serialization to  a file / read serialized data from a file and store the
instances in the register.

In the register there may be 2 
different kinds of vehicles: boats and aircrafts. Every type of these
3 has their own specific variables:

Boat:

* name (string)
* draft (double)
* power (double)

Aircraft:

* model (string)
* wingspan (double)
* cruise speed (unsigned int)

These vehicle types also share common member variables, such as register
number and owner. These are implemented already in the Vehicle class. So
these 2 types of vehicle classes inherit from the Vehicle class.

You need to implement the *Register*, *Vehicle*, *Boat* and *Aircraft* 
classes. More information in the *.hpp* files.