#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

/**
 * Problem statement
 * https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473
 *
 * Optimized Approch: T(log(max-min)*(row*log(col))), S(1)
 * First we need a range for BS so find the smallest and largest element from the 1st
 * and last column of matrix
 * That min to max element is our range, now we'll find the position we need
 *              => pos=(row*column)/2
 * now apply binary search, and find at which position the Mid element occurs in matrix
 * using a "find" function.
 * After that if mid occurs before or exactly at "pos", then eliminate the left part.
 * Else it occusre beyond "pos", then eliminate the right part.
 * Finally return the "low" value.
 */

int upperBound(vector<int> &arr, int x, int n)
{
    int ans = n, l = 0, h = n - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == x)
        {
            l = m + 1;
        }
        else if (arr[m] > x)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int countElement(vector<vector<int>> &arr, int elem, int r, int c)
{
    int count = 0;
    for (auto i : arr)
    {
        count += upperBound(i, elem, c);
    }
    return count;
}

int median(vector<vector<int>> &arr, int r, int c)
{
    int l = INT_MAX, h = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        // find smallest number
        l = min(l, arr[i][0]);
        // find largest number
        h = max(h, arr[i][c - 1]);
    }
    int pos = (r * c) / 2;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        // count what would be the position of Mid in 1D result array
        // It is basically Upper Bound of Mid in 1D result array.
        int count = countElement(arr, mid, r, c);
        if (count <= pos)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}}; // Example input
    int r = arr.size();
    int c = arr[0].size();

    cout << "Matrix: " << endl;
    for (const auto &row : arr)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    int result = median(arr, r, c);

    cout << "The median of the row-sorted matrix is: " << result << endl;

    return 0;
}