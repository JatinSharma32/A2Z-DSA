#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

/**
 * Find the Maximum Subarray sum
 *
 * Brute Force: T(n^3), S(1)
 * See all subarrays and find max sum
 *
 * Better Approch: T(n^2), S(1)
 * Store prefix sum in original array, and then travers from back
 * fix an element and find all the subarray sums from that element to start.
 *
 * Optimized Approch: T(n), S(1)
 *                      Kadane's Algorithm
 * - Only take those elements in sub array which contributes some thing in sum
 *   basically gives over all sum Positive or Zero.
 * - We keep sum variable to keep Sub array sum till now, and a max element to keep max
 *   sub array sum till now
 * - Initially sum starts with zero, we traverse in the array while adding up current
 *   element, and comparing & updating max element, if sum gets negative that means
 *   its has nothing to contribute in further subarray,
 *   so we neglet it and make the sum zero.
 *
 *
 */

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxElem = INT_MIN;
        for (auto i : nums)
        {
            sum += i;
            maxElem = max(maxElem, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxElem;
    }
    void maxSubArrayReturn(vector<int> &nums)
    {
        int maxElemIndex = 0, maxElem = INT_MIN, n = nums.size(), sum = 0, zeroIndex = -1, AnsStart = -1;
        for (int p = 0; p < n; p++)
        {
            sum += nums[p];
            if (sum == max(maxElem, sum))
            {
                maxElem = sum;
                maxElemIndex = p;
                AnsStart = zeroIndex;
            }
            if (sum < 0)
            {
                sum = 0;
                zeroIndex = p;
            }
        }
        for (int i = AnsStart + 1; i <= maxElemIndex; i++)
        {
            cout << nums[i] << " ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    sol.maxSubArrayReturn(nums);
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}