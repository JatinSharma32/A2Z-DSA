#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

/**
 * Find the floor and ciel of a number in the given sorted array with BS
 *  => Floor of 'x' is the largest element in the array which is smaller
 *     than or equal to 'x'.
 *  => Ceiling of 'x' is the smallest element in the array greater than
 *     or equal to 'x'.
 *
 * Brute force: T(n) S(1)
 * Using linear Search
 *
 * Optimized Approch: T(logn) S(1)
 * So basically if we observe, Ciel is just Lower bound, if we can find it
 * wuth Binary search we can easily find the floor value which will always
 * be one index before ciel value
 *      => exception is when ciel is equal to 'x', floor will be same
 *      => or if ciel>'x' and at 0th index then floor will be -1
 *      => or there is no ciel of 'x' floor will be last index.
 */

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int l = 0, h = n - 1;
    int ans = n;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] >= x)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    int ceil, floor;
    if (a[ans] == x)
    {
        return {x, x};
    }
    if (ans == 0)
    {
        floor = -1;
    }
    else
    {
        floor = a[ans - 1];
    }
    if (ans == n)
    {
        ceil = -1;
    }
    else
    {
        ceil = a[ans];
    }

    return {floor, ceil};
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19}; // Example input
    int x = 5;                                   // Example target

    // Sort the array (if not already sorted)
    sort(arr.begin(), arr.end());

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);

    cout << "Floor of " << x << ": " << result.first << endl;
    cout << "Ceil of " << x << ": " << result.second << endl;

    return 0;
}