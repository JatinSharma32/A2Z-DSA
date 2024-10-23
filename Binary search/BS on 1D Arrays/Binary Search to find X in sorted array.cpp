#include <iostream>
#include <vector>
using namespace std;

/**
 * Implement Binary search Algorithm iterativly and Recursivly to find 'X'
 *
 * Approch: T(logn) S(1)
 * We can utilize the sorted property of array, as we do in dictionary
 *   => We will see the middle element if its equal to X then we found
 *   => if its larger then 'X' means 'X' will be some where before it
 *      So we eliminate the half part appearing after Middle/Current element
 *   => else it will be smaller then 'X' means it will be some where after
 *      Current element, so eliminate the previous half part.
 *
 * Do this till the element is found or there remains no search space.
 */

class Solution
{
public:
    int BinarySearchRecursive(vector<int> &nums, int target, int l, int h)
    {
        if (l > h)
        {
            return -1;
        }
        int mid = (l + h) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
        return BinarySearchRecursive(nums, target, l, h);
    }

    int BinarySearchIterative(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1; // Target not found
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

    int result1 = sol.BinarySearchIterative(nums, target);
    int result2 = sol.BinarySearchRecursive(nums, target, 0, nums.size() - 1);

    if (result1 != -1)
    {
        cout << "Target " << target << " found at index: " << result1 << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}