#include <iostream>
#include <vector>
using namespace std;

/**
 * Read Problem statement from
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * Brute force: T(row*column) S(1)
 * Check each element in matrix with 2 loops.
 *
 * Better approch: T(nlogm) S(1)
 * For each row apply Binary search on it.
 *
 * Optimized Approch: (row+column) S(1)
 * Check the incode comments
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[r - 1][c - 1])
        {
            return false;
        }
        // We'll start from the top right corner, because here we
        // get the pattern that all the elements before in the same row are
        // smaller and all elements in the same column after it are larger.

        // So we can use this property to eliminate the column or row
        int i = 0, j = c - 1;
        while (i < r && j >= 0)
        {
            // Current element is target so return found: "true"
            if (matrix[i][j] == target)
            {
                return true;
            }
            // Current element and all the elements in the same column will be
            // greater than target so eliminate this column from search space
            else if (matrix[i][j] > target)
            {
                j--;
            }
            // Current element and all the elements in the same row will be
            // smaller than target so eliminate this row from search space
            else
            {
                i++;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}}; // Example input
    int target = 5;            // Example target

    cout << "Matrix: " << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    bool result = sol.searchMatrix(matrix, target);

    if (result)
    {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}