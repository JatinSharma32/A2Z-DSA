#include <iostream>
#include <vector>
using namespace std;

/**
 * Print a matrix in sprical order
 * [1,2,3]
 * [4,5,6]    =>    [1,2,3,6,9,8,7,4,5]
 * [7,8,9]
 *
 * Optimal Solution: T(n^2), S(1)
 * We will take 4 variables to keep track of traversed rows and columns
 * and further only traverse those which are not traversed before
 *      rowStart = 0;
 *      rowEnd = matrix.size() - 1
 *      colStart = 0
 *      colEnd = matrix[0].size() - 1
 * now we will traverse in such a way that
 *      traverse rowStart complete then increase it
 *      then, traverse colEnd then decrease it (ignoring rowStart's last elem)
 *      then, traverse rowEnd then decrease it (ignoring colEnd's last elem)
 *      then, traverse colStart then increase it (ignoring rowEnd's first elem)
 *
 * these 4 loops will run untill m*n (whole matrix) is traversed
 */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        int colStart = 0, rowStart = 0;
        vector<int> result;
        while (result.size() <= matrix.size() * matrix[0].size())
        {
            if (!(rowEnd >= rowStart && colEnd >= colStart))
            {
                break;
            }
            for (int i = colStart; i <= colEnd; i++)
            {
                result.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            if (!(rowEnd >= rowStart && colEnd >= colStart))
            {
                break;
            }
            for (int i = rowStart; i <= rowEnd; i++)
            {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if (!(rowEnd >= rowStart && colEnd >= colStart))
            {
                break;
            }
            for (int i = colEnd; i >= colStart; i--)
            {
                result.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            if (!(rowEnd >= rowStart && colEnd >= colStart))
            {
                break;
            }
            for (int i = rowEnd; i >= rowStart; i--)
            {
                result.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        return result;
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

    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral order:" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}