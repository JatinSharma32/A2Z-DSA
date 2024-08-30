#include <bits/stdc++.h>
using namespace std;

/**
 * Single Number
 * We are given an array of size n, it contains pair of same numbers
 * but one number is single, and we have to find it
 *
 * Brute force: T(n.logn), S(Max Element)
 * Make a map & store its <value, frequency> and finally
 * find a value with freq 1 in Map and return it
 *
 * Optimized Approch: T(n), S(1)
 * Here we can utilize the Property of XOR, that same elements gives zero
 * so if we XOR all elements in array then due 2 same numbers they will get cancelled
 * and only elements with single occurance will be left.
 *
 */

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int XOROfArray = 0;
        for (auto i : nums)
        {
            XOROfArray = XOROfArray ^ i;
        }
        return XOROfArray;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    int singleElement = solution.singleNumber(nums);
    cout << "The single element is: " << singleElement << endl;

    return 0;
}