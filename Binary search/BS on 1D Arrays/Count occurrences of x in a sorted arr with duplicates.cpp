#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a sorted array Arr of size N and a number X, you need to find the
 * number of occurrences of X in arr.
 * {1, 1, 2, 2, 2, 2, 3} find 2 => 4 occurrences
 *
 * Brute force: T(n), S(1)
 * Using linear search
 *
 * Optimized Approch: T(logn), S(1)
 * Similar to floor and ciel problem, here index of ciel - index of floor
 * will be the number of occurance.
 *
 */

class Solution
{
public:
    int count(vector<int> arr, int n, int x)
    {
        int l = 0, h = n - 1;
        int LB = n, UB = n;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] >= x)
            {
                LB = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (LB == n || arr[LB] != x)
        {
            return 0;
        }
        l = 0;
        h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] > x)
            {
                UB = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return UB - LB;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 7, 7, 8, 8, 10}; // Example input
    int target = 8;                        // Example target

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.count(arr, arr.size(), target);

    cout << "First and last occurrence of " << target << ": [" << result << endl;

    return 0;
}