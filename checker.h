#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;



static int CalcDeterminant(vector<vector<int>> Matrix)
{
    //This function was provided by Ibrahim Khalil (https://stackoverflow.com/users/8520315/ibrahim-khalil)
    //From question: 7898305 (https://stackoverflow.com/questions/7898305/)

    //this function is written in c++ to calculate the determinant of matrix
    // it's a recursive function that can handle matrix of any dimension
    int det = 0; // the determinant value will be stored here
    if (Matrix.size() == 1)
    {
        return Matrix[0][0]; // no calculation needed
    }
    else if (Matrix.size() == 2)
    {
        //in this case we calculate the determinant of a 2-dimensional matrix in a 
        //default procedure
        det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        return det;
    }
    else
    {
        //in this case we calculate the determinant of a squared matrix that have 
        // for example 3x3 order greater than 2
        for (int p = 0; p < Matrix[0].size(); p++)
        {
            //this loop iterate on each elements of the first row in the matrix.
            //at each element we cancel the row and column it exist in
            //and form a matrix from the rest of the elements in the matrix
            vector<vector<int>> TempMatrix; // to hold the shaped matrix;
            for (int i = 1; i < Matrix.size(); i++)
            {
                // iteration will start from row one cancelling the first row values
                vector<int> TempRow;
                for (int j = 0; j < Matrix[i].size(); j++)
                {
                    // iteration will pass all cells of the i row excluding the j 
                    //value that match p column
                    if (j != p)
                    {
                        TempRow.push_back(Matrix[i][j]);//add current cell to TempRow 
                    }
                }
                if (TempRow.size() > 0)
                    TempMatrix.push_back(TempRow);
                //after adding each row of the new matrix to the vector tempx
                //we add it to the vector temp which is the vector where the new 
                //matrix will be formed
            }
            det = det + Matrix[0][p] * pow(-1, p) * CalcDeterminant(TempMatrix);
            //then we calculate the value of determinant by using a recursive way
            //where we re-call the function by passing to it the new formed matrix
            //we keep doing this until we get our determinant
        }
        return det;
    }
}

int checkDefinite(vector<vector<int>> Matrix, int size) {

    /*
        Checks if a matrix is Positive Definite.
        As the Thomas algorithm not stable on other type of definite matrices.

        Wiki quote:
        "Thomas' algorithm is not stable in general, but is so in several special cases, such as when the matrix is diagonally dominant (either by rows or columns) or symmetric positive definite...
        If stability is required in the general case, Gaussian elimination with partial pivoting (GEPP) is recommended instead."
    */

    if (size == 1) {
        if (Matrix[0][0] < 0) {
            return 1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        vector<vector<int>> temp(i + 1, vector<int>(0));
        for (int j = 0; j < i + 1; j++)
        {
            for (int k = 0; k < i + 1; k++)
            {
                temp[j].push_back(Matrix[j][k]);
            }
        }

        if (CalcDeterminant(temp) < 0) {
            return 1;
        }
    }

    return 0;
}

int isDiagonallyDominant(vector<vector<int>> Matrix, int size) {

    /*
        Checks if a matrix is Diagonally Dominant.
        As the Thomas algorithm not stable on other type of definite matrices.

        Wiki quote:
        "Thomas' algorithm is not stable in general, but is so in several special cases, such as when the matrix is diagonally dominant (either by rows or columns) or symmetric positive definite...
        If stability is required in the general case, Gaussian elimination with partial pivoting (GEPP) is recommended instead."
    */

    if (size == 1) {
        return 0;
    }
    else if (size == 2) {
        int bi = abs(Matrix[0][0]);
        int ci = abs(Matrix[0][1]);
        if (bi <= ci) {
            return 2;
        }

        bi = abs(Matrix[1][1]);
        int ai = abs(Matrix[1][0]);
        if (bi <= ai) {
            return 2;
        }
    }
    else {
        for (int i = 0; i < Matrix.size(); i++)
        {
            if (i == 0) {
                int bi = abs(Matrix[i][i]);
                int ci = abs(Matrix[i][i + 1]);
                if (bi <= ci) {
                    return 2;
                }
            }
            else if (i == Matrix.size() - 1) {
                int bi = abs(Matrix[i][i]);
                int ai = abs(Matrix[i][i - 1]);
                if (bi <= ai) {
                    return 2;
                }
            }
            else {
                if (i > 0 && i < Matrix.size() - 1) {
                    int bi = abs(Matrix[i][i]);
                    int ai = abs(Matrix[i][i - 1]);
                    int ci = abs(Matrix[i][i + 1]);
                    if (bi <= ai + ci) {
                        return 2;
                    }
                }
            }
        }

        return 0;
    }
}

void isMatrixCorrect(double(*myMatrix), int size) {

    /*
        "Driver" code of the checker.
        If errorMsg = 0 then everything correct, the algorithm is stable.
        If errorMsg = 1 then the matrix is not Positive Definite.
        If errorMsg = 2 then the matrix is not Diagonally Dominant.
        If errorMsg = 3 then both error applies.
    */

    vector<vector<int>> vectorMatrix(size, vector<int>(0));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        {
            vectorMatrix[i].push_back(*myMatrix);
            myMatrix++;
        }
    }

    int errorMsg = checkDefinite(vectorMatrix, size) + isDiagonallyDominant(vectorMatrix, size);
    switch (errorMsg) {
    case 0:
        printf("Matrix looking good.\n");
        break;
    case 1: 
        printf("Matrix is not symmetric positive definite\n");
        printf("The Thomas algortihm is not stable on such matrices.\n");
        break;
    case 2: 
        printf("Matrix is not diagonally dominant\n");
        printf("The Thomas algortihm is not stable on such matrices.\n");
        break;
    case 3:
        printf("Matrix is not diagonally dominant and not symmetric positive definite\n");
        printf("The Thomas algortihm is not stable on such matrices.\n");
        break;
    default:
        printf("How did you reach this?\n");
        break;
    }

}





