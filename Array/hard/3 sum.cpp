#include <iostream>
#include <vector>
#include <algorithm> // For sort function
#include <climits>   // For INT_MIN
using namespace std;

/**
 * Given an integer array nums, return all the triplets such that
 * nums[i] + nums[j] + nums[k] == 0 and all elements are unique.
 *
 * [-1,0,1,2,-1,-4] => [[-1,-1,2],[-1,0,1]]
 *
 * Brute Force: T(n^3) S(n)
 * Manually find 3 triplets with sum 0 usig 3 loops, while storing triplets with
 * sum 0, make sure they are not previously present in answer.
 * We can use an extra set here to do so.
 *
 * Better approch: T(n^2) S(n)
 * We can use 2 loops for 2 elements and hashing for another it nakes the TC to N^2.
 *
 * Optimized Approch: T(n^2) S(1)
 * See it as extended version of "Two sum", first sort the array then traverse it the
 * current element will be one of triplet now we have to find remaining to using
 * "Two pointers on sorted array" in linear time it works fine
 *
 *  => mean while to maintain answers are only unique, we will skip those elements in
 *  => triplet which are matching their pervious elements. arr[i]!=arr[i-1]
 *
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> result;
        int n = arr.size(), prev = INT_MIN;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++)
        {
            int findElem = arr[i];
            if (prev == findElem)
            {
                prev = arr[i];
                continue;
            }
            int sum = 0, s = i + 1, e = n - 1;
            while (s < e)
            {
                sum = arr[s] + arr[e];
                if (sum == (-1 * findElem))
                {
                    result.push_back({findElem, arr[s], arr[e]});
                    s++;
                    while (arr[s] == arr[s - 1] && s < e)
                        s++;
                }
                else if (sum < (-1 * findElem))
                    s++;
                else
                    e--;
            }
            prev = arr[i];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<int>> result = sol.threeSum(arr);

    cout << "Triplets with sum zero:" << endl;
    for (const auto &triplet : result)
    {
        cout << "[";
        for (int val : triplet)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}