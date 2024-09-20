#include <bits/stdc++.h>
using namespace std;

/**
 * We are given a matrix with some zeros and non zeros, we have to update it
 * such that if a element is zero its whole row and column will be come zero.
 *
 * {0,1,2,0}        {0,0,0,0}
 * {3,4,5,2}   =>   {0,4,5,0}
 * {1,3,1,5}        {0,3,1,0}
 *
 * Brute Force: T(n*m*(m+n)) OR (n^3), S(1)
 * Traverse the matrix when ever found zero update that whole column and row
 * to [-1] then again traverse the matrix, when ever found -1 update it to zero.
 *
 * Better Approch: T(n*m), S(n+m)
 * Take 2 unordered sets, we will use them for storing a mark for zero
 * in row or column. Then we traverse matrix if elements is found zero, its
 * row and column index are stored in both sets.
 * Then we will traverse both sets seperatly and mark those rows and colums to zero.
 *          -> We can also use seperate arrays instead of sets.
 *
 * Best Approch: T(n*m), S(1) Inplace
 * Its similar to Better approch here
 *      -> We gona use 0th column as mark array for Rows
 *      -> We gona use 0th row as mark array for Columns
 *      -> [0,0] is overlapping in this way so for 0th column mark we will use an
 *         extra variable "col0".
 * Traverse the matrix and put all marks in 0th row, 0th column and col0 again
 * traverse the matrix from end to start ingoring 0th row and column and update
 * current element to zero if 0th row or column or both are marked.
 * finally seperatly handle the 0th row using [0,0] mark, and 0th column using col0
 *
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j == 0)
                    {
                        col0 = 0;
                    }
                    else
                    {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (int i = r - 1; i > 0; i--)
        {
            for (int j = c - 1; j > 0; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = r - 1; i >= 0; i--)
            {
                matrix[i][0] = 0;
            }
        }
    }
    void setZeroesUsingSets(vector<vector<int>> &matrix)
    {
        unordered_set<int> colsWithZero, rowsWithZero;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowsWithZero.insert(i);
                    colsWithZero.insert(j);
                }
            }
        }
        for (auto i : rowsWithZero)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for (auto j : colsWithZero)
        {
            for (int i = 0; i < r; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    sol.setZeroes(matrix);

    cout << "Matrix after setting zeroes:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}