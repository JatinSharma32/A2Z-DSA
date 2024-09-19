#include <iostream>
#include <vector>
using namespace std;

/**
 * DOCS PENDING
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