**Objective:** Practice use of C++ strings and vectors.

Implement a program that stores and removes given strings from a
vector, as commanded by the user. You should implement a simple
command line interface that implements the following.

In the beginning, program should print `Commands: ADD, PRINT, REMOVE, QUIT`, 
followed by a newline. Then print `Enter a command:` followed by a newline. 
Then the program should read the command from the user and do the following:

  * **ADD**: Add a given string to the vector. The program should first
    prompt: `Enter a name:` (without trailing space) followed by a newline. Then
    it reads the name from the user and adds it to a the
    vector. Finally, it prints: `Number of names in the vector:`, a
    newline, the size of the vector, and finally newline. The ADD
    functionality is implemented in the function `Adder`.
  
  * **REMOVE**: Removes the last string from the vector. This
    operation is implemented in the function `Remover`. The function
    should print the removed string in the following way: `Removing
    the last element:`, followed by a newline, then the string and a
    newline.

  * **PRINT**: Outputs all stored strings, each on a separate line
    (e.g., followed by newline character). This operation is
    implemented in function `Printer`.

  * **QUIT**: Exit the program.

In addition to the above three functions, you need to implement
the function `CMDReader` that parses the commands and calls the
appropriate functions. The detailed function interfaces can be found
in the file *vector_strings.hpp*.

Here is an example of an session:

Commands: ADD, PRINT, REMOVE, QUIT
Enter a command:
ADD
Enter a name:
Erkki
Number of names in the vector:
1
Enter a command:
ADD
Enter a name:
Tiina
Number of names in the vector:
2
Enter a command:
PRINT
Erkki
Tiina
Enter a command:
REMOVE
Removing the last element:
Tiina
Enter a command:
QUIT

Instructions on how to run and test your programs locally are available
in Module 0.