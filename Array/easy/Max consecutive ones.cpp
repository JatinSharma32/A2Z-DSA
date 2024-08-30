#include <bits/stdc++.h>
using namespace std;

/**
 * Max consecutive ones
 * Find the length of longest subarray of 1's.
 * [1,1,0,1,1,1] -> 3
 *
 * Optimal Solution: T(n), S(1)
 * Keep a Current counter of consecutive ones, which increase by one if current element
 * is 1, otherwise get 0.
 * On each iteration keep and update the maxSum till all previous elements.
 *
 */

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxSum = 0, currSum = 0;
        for (auto i : nums)
        {
            if (i == 1)
                currSum++;
            else
                currSum = 0;
            if (currSum > maxSum)
            {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Example input

    int maxConsecutiveOnes = solution.findMaxConsecutiveOnes(nums);
    cout << "The maximum number of consecutive 1s is: " << maxConsecutiveOnes << endl;

    return 0;
}