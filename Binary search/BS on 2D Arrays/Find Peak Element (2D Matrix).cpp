#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

/**
 * Problem statement:
 * https://leetcode.com/problems/find-a-peak-element-ii/
 *
 * Brute Force: T(row*column), S(1)
 * Go through every element and check if its Peak by comparing it with all of
 * (top, left, right, bottom) elements.
 *
 * Optimized Approch: T(column*log(row)), S(1)
 * Here we'll traverse the Rows using Binary search [0 to row] on mid row we apply
 * Linear search to find the Peak element, cause it holds the largest possiblity of
 * being the peak element.
 * Now check this Max element if its top and bottom are smaller then return the
 * indexes its PEAK
 * If Any of Top or bottom are larger then Peak then using Binary search eliminate
 * half of the rows(search space) like...
 *  => If (top < current < bottom) so remove rows having smaller elements on top.
 *  => If (top > current > bottom) so remove rows having smaller elements in bottom.
 *
 *
 *
 * NOTE: This question is similar to (Peak in 1D Array), that we Linearly traverse
 * every row and then for each row we apply (Peak in 1D Array) approch
 *    => apply Binary search from [0 to column]
 *          => if current element is Peak element COLUMN WISE
 *              -> Now Check If its grater then both Top & Bottom, then its a
 *                 VALID Peak Element return the indexes
 *  -------------> If not then HERE COMES THE CATCH <---------------
 *                 What to be done now, which columns to eliminate, we have no idea
 *                 or either we should break of this row and check in the next
 *                 THAT's WHY THIS APPROCH IS NOT WORKING HERE.
 *
 *          => else if prev<current<next (increasing curve) then eliminate the
 *             smaller elements in left half.
 *          => else prev>current>next (decreasing curve) then eliminate the smaller
 *             elements in right half.
 */

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int row = arr.size(), col = arr[0].size();
        int l = 0, h = row - 1;
        while (l <= h)
        {
            int i = (l + h) / 2;
            // find the max element of this row
            int mx = INT_MIN, maxi, maxj;
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] > mx)
                {
                    maxi = i;
                    maxj = j;
                    mx = arr[i][j];
                }
            }
            // this extra step is done to handle edge cases
            int top, bottom;
            if (maxi == 0)
            {
                top = -1;
            }
            else
            {
                top = arr[maxi - 1][maxj];
            }
            if (maxi == row - 1)
            {
                bottom = -1;
            }
            else
            {
                bottom = arr[maxi + 1][maxj];
            }

            if (arr[maxi][maxj] > top && arr[maxi][maxj] > bottom)
            {
                return {maxi, maxj};
            }
            else if (top < arr[maxi][maxj] && arr[maxi][maxj] < bottom)
            {
                l = maxi + 1;
            }
            else
            {
                h = maxi - 1;
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {
        {1, 4, 3, 2},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}}; // Example input

    cout << "Matrix: " << endl;
    for (const auto &row : arr)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> result = sol.findPeakGrid(arr);

    cout << "Peak element found at: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}