#ifndef AALTO_ELEC_CPP_MATRIX
#define AALTO_ELEC_CPP_MATRIX

#include <vector>

typedef std::vector<std::vector<int>> Matrix;

// Function reads input from user to n x n matrix,
// one number at a time.
Matrix ReadMatrix(int n);


// Function rotates n x n matrix 90 degrees clockwise
// and stores it to a new matrix that it returns
Matrix Rotate90Deg(const Matrix & );

/* Function prints n x n matrix to standard output:
 * e.g. when n = 3 and the matrix' rows are all 1,2,3:
Printing out a 3 x 3 matrix:\n
1 2 3 \n
1 2 3 \n
1 2 3 \n
 */
void Print(const Matrix &  mat);

#endif
