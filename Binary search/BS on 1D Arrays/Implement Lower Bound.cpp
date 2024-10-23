#include <iostream>
#include <vector>
using namespace std;

/**
 * Lower bound of 'X' in array is the first appearing element that is greater
 * then or equal to 'X'.
 *
 * arr[] = {1,2,2,3} , x = 2
 * OUTPUT=> 2
 *
 * arr[] = {3,5,8,15,19}, x = 9
 * OUTPUT=> 15
 *
 * Optimized approch: T(logn) S(1)
 * We'll use binary search, and initilize a variable 'ans' to out of array (n)
 *   => Now, if the mid value is >= 'X', it means this element might be our
 *      Upper bound, so update the 'ans' and then check if perviously some
 *      other element may be there which can be upper bound.
 *   => Else mid value is < 'X', it means the upper bound will be in the after
 *      part of array from mid, so update it as low=mid+1.
 */

class Solution
{
public:
    int LB(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1, ans = nums.size();
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans; // Target not found
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example input
    int target = 5;                                 // Example target

    cout << "Array: ";
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.LB(nums, target);

    cout << "Lower bound of " << target << " is: " << nums[result] << endl;

    return 0;
}