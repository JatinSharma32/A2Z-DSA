#include <bits/stdc++.h>
using namespace std;

/**
 * Two sum
 * Given an array of integers V and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * Brute Force: T(n^2), S(1)
 * Run 2 loops fix a element in outer loop and sum up it with
 * all elements in inner loop if found target then return indexes.
 *
 * Better Approch: T(n), S(n)
 * We will traverse the array and in each iteration we store the complement
 * of current element (target - v[i])
 * and check if complement of current element is in map
 * if yes return the indexes, other wise store {v[i],index} in a map
 *
 * Optimized Approch: T(n.logn), S(1)    ---    {Not for Index return}
 * Sort array and use 2 pointer approch, i at start and j at end, till they
 * cross each other
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &v, int target)
    {
        int n = v.size();
        vector<int> ans;
        unordered_map<int, int> index = {{v[0], 0}};
        for (int i = 1; i < n; i++)
        {
            auto x = index.find(target - v[i]);
            if (x != index.end())
            {

                ans.push_back(x->second);
                ans.push_back(i);
                break;
            }
            index[v[i]] = i;
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> V = {10, 5, 2, 7, 1, 9};
    int target = 10;
    auto result1 = sol.twoSum(V, target);
    for (auto i : result1)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}