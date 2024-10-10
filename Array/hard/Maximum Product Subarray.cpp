#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

/**
 * Given an Array, we have o find the maximum product we could get form any subarray
 * [1,2,-3,0,-4,-5]     =>     20
 *
 * Better Approch: T(n^2), S(1)
 * We can traverse the array on each iteration we declare a multiple variable
 * and again inside a loop from curent element to last calcuate the product and
 * update it with maximum.
 *
 * Best Approch: T(n), S(1)
 * This approch is observation based in which, the max sum will always be Prefix
 * or Suffix of current element.
 * So calculate the prefix product and sufix product if comes 0 then reset it to 1
 * then everytime keep updating the maximum Product.
 */

class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size(); // size of array.

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }

    int maxProductBetterApproch(vector<int> &arr)
    {
        int maxProd = 0, prod = 1;
        if (arr.size() == 1)
        {
            return arr[0];
        }
        vector<pair<int, int>> res;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                prod = 1;
                res.push_back({prod, arr[i]});
                continue;
            }
            prod *= arr[i];
            if (prod < 0)
            {
                int itr = res.size() - 1;
                while (itr >= 0)
                {
                    if ((res[itr]).second == 0)
                        break;
                    maxProd = max(maxProd, prod / ((res[itr]).first));
                    // cout << (res[itr]).first << " " << (res[itr]).second
                    //  << "\n";
                    itr--;
                }
                res.push_back({prod, arr[i]});
                continue;
            }
            res.push_back({prod, arr[i]});
            maxProd = max(maxProd, prod);
        }
        return maxProd;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, -2, 4}; // Example input

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.maxProduct(arr);

    cout << "Maximum product of subarray: " << result << endl;

    return 0;
}