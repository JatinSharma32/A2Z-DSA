#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Find the longest subarray with sum zero
 * {9, -3, 3, -1, 6, -5} => 5
 *      ^  ^   ^  ^   ^
 *
 * Brute Force / Better Solution: T(n^3)/T(n^2) S(1)
 * Find out all the sub arrays either by traversing everytime of keeping
 * a common sum variable between both limits.
 *
 * Optimized Approch: T(n) S(n)
 * Here we utilize the Unordered Map Data structure where we can store the
 * Prefix sum whit its index, which can be used to find the desired sum at any index
 *
 * Array      : {9, -3, 3, -1,  6, -5}
 * Prefix Sum : {9,  6, 9,  8, 14,  9}
 *
 * so on each index find the sum till now and find if that sum if previously present
 * if yes then calculate length and compare and update max length
 * and finally push that current sum in Map with index.
 *
 */

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> result;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLen = max(maxLen, i + 1);
            }
            auto found = result.find(sum);
            if (found != result.end())
            {
                maxLen = max(maxLen, i - found->second);
                continue;
            }
            result[sum] = i;
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.maxLen(arr, n);
    cout << "Length of the longest subarray with zero sum: " << result << endl;

    return 0;
}