#include <iostream>
#include <vector>
using namespace std;

/**
 * A sorted array is rotated on a piviot, we have to find 'x' in it and return its index.
 * [4,5,6,7,0,1,2] find 0 => at index 4
 *
 * Brute force: T(n) S(1)
 * Using linear search
 *
 * Optimized Approch: T(logn) S(1)
 * Using binary search, So we'll check the mid element if its grater then lower limit it
 * it means that left part of mid is sorted and slso if 'x' is in left part if so then
 * eliminate the right half from mid to high
 * otherwise eliminate the left part
 *
 * if mid element if smaller then high limit then it means right part of mid is sorted
 * also if 'x' is in right part then we can eliminate the left part.
 * otherwise eliminate the right part
 *
 * finally check if mid is 'x' then return its index.
 */

class Solution
{
public:
    int search(vector<int> &arr, int x)
    {
        int n = arr.size();
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            // check if mid is the 'x'
            if (arr[mid] == x)
            {
                return mid;
            }
            if (arr[l] <= arr[mid])
            {
                if (arr[l] <= x && x <= arr[mid])
                {
                    /*
                    this means thats left part is sorted, = in above condition
                    makes this code working even is the low and mid elem are
                    same;
                    */
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (arr[mid] <= arr[h])
            {
                if (arr[mid] <= x && x <= arr[h])
                {
                    /*
                    this means thats right part is sorted, = in above condition
                    makes this code working even is the mid and high elem are
                    same;
                    */
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2}; // Example input
    int target = 0;                          // Example target

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.search(arr, target);

    if (result != -1)
    {
        cout << "Target " << target << " found at index: " << result << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}