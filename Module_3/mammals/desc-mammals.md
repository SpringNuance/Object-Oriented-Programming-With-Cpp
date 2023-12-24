**Objective:** Practice defining inherited classes that contain static
members

Below code contains a definition of a **Mammal** class (click *Show all code*), 
and a main function
that uses this class along with a **Dog** class and a **Cat** class.
However, definitions of these classes are missing. Implement these classes
according to the following:

* Both classes should inherit the Mammal class.

* Both classes should have a constructor with two arguments. The first
argument is a string representing the name of the creature, and the second
argument is the weight. Remember that the weight attribute is common to all
Mammals, and is stored in the base class.

* Implement accessor function **GetName** that returns the name of the
creature.

* Implement static function **MakeSound** that returns a string that
contains the sound that the creature makes. A dog should say `Wuff!`
and a cat should say `Meow`

Investigate how the main function is implemented by pressing *Show all
code* button, and how it uses these classes.
Define the classes so that they compile together with the main function
without producing errors or warnings when compiled.

You will receive points when the main function output is as expected:

    Mammal's weight is 10.5
    Ransu weighs 23.1 and says: Wuff!
    Ransu is a Mammal
    Garfield weighs 16.5 and says: Meow
    Garfield is a Mammal
    In fact, all dogs say Wuff!
