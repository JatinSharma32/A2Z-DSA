#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

/**
 * We have to find 4 numbers in the Array which sum up to target value
 * [4,3,3,4,4,2,1,2,1,1], target = 9
 *
 * Brute force: T(n^4) S(1)
 * Run 4 loops, one for each number, calculate sum of 4s and then
 * return if equal to target.
 *
 * Optimized Approch: T(n^3) S(1)
 * Similar to "Two Sum" & "Three Sum" we merge 2 loops in one and reduce
 * an extra "n" from Time complexity.
 * First Sort the array,
 *  -> then run a loop to find variable one if its similar to pervious then skip.
 *  -> inside, run another loop to find number two if its similar to previous then skip.
 *  -> indise, we will select 2 variables together using concept of "two sum".
 *
 */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                long long elem = (arr[i] + arr[j]);
                long long find = target - elem;
                int s = j + 1, e = n - 1;
                while (s < e)
                {
                    int sum = arr[s] + arr[e];
                    if (sum > find)
                    {
                        e--;
                    }
                    else if (sum < find)
                    {
                        s++;
                    }
                    else
                    {
                        result.push_back({arr[i], arr[j], arr[s], arr[e]});
                        s++;
                        while (s < e && arr[s - 1] == arr[s])
                            s++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<int>> result = sol.fourSum(arr, target);

    cout << "Quadruplets with sum " << target << ":" << endl;
    for (const auto &quadruplet : result)
    {
        cout << "[";
        for (int val : quadruplet)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}