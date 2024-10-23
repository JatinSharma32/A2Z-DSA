#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <numeric>   // For accumulate
using namespace std;

/**
 * Description read from:
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * Brute force: T( n * ( sumOfArray - maxOfArray )), S(1)
 * We have the range (Max of Array to Sum of Array) between which our answer will lie
 * so we'll apply linear search on this range to check for how low the max sum of
 * subarray can go.
 *
 * We'll use noOfSubarrays function to find how many subarrays can be made with
 * that max limit being there. It works as:
 * We'll keep giving elements to a subarray till that it is not hitting the max
 * sum limit, if it hits then stop putting elements in this subarray, and put it in
 * new subarray. Finally return how many subarrays can be made.
 *
 * Optimized Approch: T(n * log(sumOfArray - maxOfArray) ), S(1)
 * We'll just apply Binary search at the place Linear search.
 *
 *    Max(Arr)----------------------|-----------------------Sum(Arr)
 *                                 Mid
 *                 <-----                      ----->
 *             No of subarrays             No of subarrays
 *                Increases                   decreases
 */

class Solution
{
public:
    int noOfSubarrays(vector<int> &arr, int maxSum)
    {
        int subArray = 1, sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (sum + arr[i] > maxSum)
            {
                subArray++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }
        return subArray;
    }

    int splitArray(vector<int> &arr, int k)
    {
        if (k > arr.size())
        {
            return -1;
        }
        int l = *(max_element(arr.begin(), arr.end()));
        int h = accumulate(arr.begin(), arr.end(), 0);
        int ans;
        while (l <= h)
        {
            int m = (l + h) / 2;
            int subArrays = noOfSubarrays(arr, m);
            if (subArrays <= k)
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
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 2, 5, 10, 8}; // Example input
    int k = 2;                          // Example number of subarrays

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.splitArray(arr, k);

    cout << "The largest sum among the subarrays is: " << result << endl;

    return 0;
}