#include <iostream>
#include <vector>
#include <algorithm> // For reverse function
using namespace std;

/**
 * Given a square matrix we have to rotate it 90 degree
 *
 * Brute force: T(n^2), S(n^2)
 * Make a dummy matrix rotated and for each element just
 *      rotated[j][n - i - 1] = matrix[i][j];
 *
 * Optimized Approch: T(n^2), S(1) (Observation Based)
 * Transpose the matrix in upper half only (to avoid double swapping of same element)
 * and then reverse every row (Observation).
 *
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = i + 1; j < c; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (auto &i : matrix)
        {
            reverse(i.begin(), i.end());
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    sol.rotate(matrix);

    cout << "Matrix after 90 degree rotation:" << endl;
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