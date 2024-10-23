#include <iostream>
#include <vector>
using namespace std;

/**
 * Upper bound of 'X' in array is the first appearing element that is greater
 * then 'X'.
 *
 * arr[] = {1,2,2,3} , x = 2
 * OUTPUT=> 3
 *
 * arr[] = {3,5,8,15,19}, x = 9
 * OUTPUT=> 15
 *
 *
 * Optimized Approch: T(logn) S(1)
 * We'll use binary search, and initilize a variable 'ans' to out of array (n)
 *   => Now in binary search if the mid value is == 'X', it means the Upper bound
 *      will be after it so update the lower limit to mid + 1.
 *   => Else if the mid value is > 'X', it means this element might be our
 *      Upper bound, so update the 'ans' and then check if perviously some
 *      other element may be there which can be upper bound.
 *   => Else mid value is < 'X', it means the upper bound will be in the after
 *      part of array from mid, so update it as low=mid+1.
 *
 */

class Solution
{
public:
    int UB(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1, ans = nums.size();
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
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

    int result = sol.UB(nums, target);

    cout << "Upper bound of " << target << " is: " << nums[result] << endl;

    return 0;
}