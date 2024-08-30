#include <bits/stdc++.h>
using namespace std;

/**
 * Missing Number
 * Given an unsorted array of size N with elements from [0 to n], there will always
 * be one element absent find it.
 * [3,0,1]          -> 2
 * [0,1]            -> 2
 * [0,1,2,4]        -> 3
 * [1,2,3]          -> 0
 *
 * Brute Force: T(n.logn), S(1)
 * First sort the array then check for edge case if (arr[0] is not 0) return 0,
 * then run loop from [1 , n-1] where we substract current element from previous,
 * if not 1 for any case then return current element-1 other wise after loop ends
 * return n as its also an edge case like arr[0]==0.
 *
 * Optimal Approch: T(N), S(1)
 * Sum up all the elements in the array, find the diffrence of it with
 * sum of N natural numbers, as the number which will not be in array will not be in sum
 * So returned in difference.
 *
 *                              OR
 * Using XOR, as we know XOR of same numbers is 0,so we will find the XOR of array and
 * XOR of N Natural numbers.
 * Then XOR them both
 *
 * XOR of array                 -> [0^1^2^4]
 * XOR of N Natural numbers     -> [0^1^2^3^4]
 * So it will be like (0^0)^(1^1)^(2^2)^(3)^(4^4) => 0^0^0^3^0
 * => 3
 *
 */

class Solution
{
public:
    // XOR
    // int missingNumber(vector<int>& nums) {
    //     int XOROfNaturalNumbers=0, XOROfArray=0, n=nums.size();
    //     for(int i=0;i<n;i++){
    //         XOROfNaturalNumbers=XOROfNaturalNumbers^(i+1);
    //         XOROfArray=XOROfArray^nums[i];
    //     }
    //     return XOROfNaturalNumbers^XOROfArray;
    // }

    // Sum
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size(), i = 0;
    //     long sumOfNaturalNumbers = n*(n+1)/2,sumOfArray=0;
    //     for(auto i:nums ){
    //         sumOfArray+=i;
    //     }
    //     return sumOfNaturalNumbers-sumOfArray;
    // }

    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        if (nums[i] != 0)
        {
            return 0;
        }
        for (i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] != 1)
            {
                return nums[i] - 1;
            }
        }
        return n;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 0, 1}; // Example input
    int missing = solution.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}