#include <iostream>
#include <vector>
#include "vector_it.hpp"

// Implement the functions here

std::vector<int> ReadVector(){
   std::vector<int> numbers;
   int num;
   std::cin >> num;
   while (std::cin){
     numbers.push_back(num);
      std::cin >> num;
   }
   return numbers;
}

// Prints the sum of each pair of adjacent elements: input: 1 2 3 4 !\n, output: 3 5 7 \n
// The vector should not be modified and is thus declared as a const
void PrintSum1(const std::vector<int>& v){
     std::vector<int>::const_iterator ptr;
     for (ptr = v.begin(); ptr < v.end() - 1; ptr++){
        std::cout << *ptr + *(ptr + 1) << " ";
     }
     std::cout << "" << std::endl;
}

// Prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
void PrintSum2(const std::vector<int>& v){
    int length = v.size();
     for (int i = 0; i < (length)/2; i++){
        std::cout << v[i] + v[length - i - 1] << " ";
     }
     std::cout << "" << std::endl;
}