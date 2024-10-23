#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <climits>   // For INT_MAX
using namespace std;

/**
 * We have an arr[n] and a threshold, find a smallest divisor that divides to all
 * the elements, and sum of all the divisions is less then or equal to threshold.
 *
 * [1,2,5,9], threshold = 6
 * OUTPUT => 6
 *
 * [44,22,33,11,1], threshold = 5
 * OUTPUT => 44
 *
 * Brute Force: T( max[nums] * n ) S(1)
 * We will do linear search from 1 to max element of nums on each element
 * we'll calculate the total sum for divisior i
 *
 * Using a function fn(nums, div)
 *  - Here we have to find the sum of divisions results of all elements
 *  - By taking ciel of division.
 *
 * If any element between 1 to max of nums gives total sum equal or less then
 * close to threshold then thats our answer.
 *
 * Optimized Approch: T( log(max[nums]) * n) S(1)
 * Just convert the linear search to Binary search in 1st step
 *
 */

class Solution
{
public:
    int sumOfFactors(vector<int> &nums, int div)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] / div) + ((nums[i] % div == 0) ? 0 : 1);
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int minDiv = INT_MAX;
        int l = 1, h = *(max_element(nums.begin(), nums.end()));
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (sumOfFactors(nums, m) <= threshold)
            {
                minDiv = min(minDiv, m);
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return minDiv;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 5, 9}; // Example input
    int threshold = 6;               // Example threshold

    cout << "Array: ";
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.smallestDivisor(nums, threshold);

    cout << "Smallest divisor to keep the sum <= " << threshold << " is: " << result << endl;

    return 0;
}