#include <iostream>
#include <vector>
using namespace std;

/**
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be
 * if it were inserted in order.
 *
 * [1,3,5,6], target = 7
 * OUTPUT=> At Index 4
 *
 * [1,3,5,6], target = 2
 * OUTPUT=> At Index 4
 *
 * [1,3,5,6], target = 5
 * OUTPUT=> At Index 4
 *
 * Optimized Approch: Its just     =>      LOWER BOUND.
 */

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1;
        int ans = h + 1;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (nums[m] >= target)
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
    vector<int> nums = {1, 3, 5, 6}; // Example input
    int target = 5;                  // Example target

    cout << "Array: ";
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.searchInsert(nums, target);

    cout << "Target " << target << " should be inserted at index: " << result << endl;

    return 0;
}