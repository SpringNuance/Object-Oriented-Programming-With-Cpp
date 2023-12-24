#include <iostream>
#include <vector>
#include <algorithm>
#include "matrix.hpp"

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

typedef std::vector<std::vector<int>> Matrix;

// Function reads input from user to n x n matrix,
// one number at a time.
Matrix ReadMatrix(int n){
    Matrix mat;
    int num;
    for (int i = 0; i < n; i++) {
        std::vector<int> vec;
        for (int j = 0; j < n; j++) {
            std::cin >> num;
            vec.push_back(num);
        }
        mat.push_back(vec);
    }
    return mat;
}

// Function rotates n x n matrix 90 degrees clockwise
// and stores it to a new matrix that it returns
Matrix Rotate90Deg(const Matrix & mat) {
   int n = mat.size();
   Matrix newMat = mat;
   // transposing
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          newMat[i][j] = mat[j][i];
        }
    }
    Matrix finalMat;
   for (auto vec : newMat){
       std::reverse(vec.begin(), vec.end());
       finalMat.push_back(vec);
   }
   return finalMat;
}

/* Function prints n x n matrix to standard output:
 * e.g. when n = 3 and the matrix' rows are all 1,2,3:
Printing out a 3 x 3 matrix:\n
1 2 3 \n
1 2 3 \n
1 2 3 \n
 */
void Print(const Matrix & mat) {
    int n = mat.size();
    std::cout << "Printing out a " << n << " x " << n << " matrix:" << std::endl;
    for (auto vec : mat){
        for (auto num : vec){
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

