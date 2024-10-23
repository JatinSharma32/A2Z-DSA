#include <iostream>
#include <vector>
using namespace std;

/**
 * Find the first or last occurrence index of a 'x' in a sorted array
 * if not in array then return -1.
 *
 * Brute force: T(n) S(1)
 * Using linear Search
 *
 * Optimized Approch: T(logn) S(1)
 * So basically if we observe 1st occurance will be lower bound and last index
 * will 1 index pervious to upper bound.
 *      => If lower bound is not 'x' or its out of the array end then there's
 *         no last or first index return -1,-1.
 *
 */

class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int x)
    {
        int n = arr.size();
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
            return {-1, -1};
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
        int FO = LB;
        int LO = UB - 1;
        return {FO, LO};
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

    vector<int> result = sol.searchRange(arr, target);

    cout << "First and last occurrence of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}