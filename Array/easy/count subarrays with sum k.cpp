#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Find all the possible sub arrays with sum k
 * {0,1,0,0,2,0,3} , k=3
 * => No of subarrays 6 => [{0,1,0,0,2},{1,0,0,2},{0,1,0,0,2,0},{1,0,0,2,0},{0,3},{3}]
 *
 * Optimized: T(n) S(n)
 * We will maintain a prefix sum of array in "unordered_map", and then traverse
 * the array on each iteration
 *  => update sum itself and to map by updating its no of times Occurance "PS[sum]++".
 *  => if sum is k then increase count
 *  => then find how many more sub arrays with sum K are there by removing previous
 *     subarrays. add them to count
 * Return count finally.
 *
 */

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int sum = 0, count = 0;
        unordered_map<int, int> ps;
        for (auto i : arr)
        {
            sum += i;
            if (sum == k)
            {
                count++;
            }
            auto v = ps.find(sum - k);
            if (v != ps.end())
            {
                count += v->second;
            }
            ps[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 1};
    int k = 2;

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.subarraySum(arr, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}