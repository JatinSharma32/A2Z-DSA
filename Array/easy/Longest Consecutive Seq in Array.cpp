#include <bits/stdc++.h>
using namespace std;

/**
 * We have to find the length of Longest Consecutive Sequence in a
 * unsorted array: Edge case if 0 elements then return 0
 *      {1,2,0,1} = 0,1,2 => 3
 *      {0,3,7,2,5,8,4,6,0,1} = 0,0,1,2,3,4,5,6,7,8 => 9
 *
 * Better Approch: T(n.logn), S(1)
 * First sort the array and then traverse and check if 2 adjecent elements are
 * consecutive if yes then increase a counter if both are same then continue
 * other wise they are totally different elements so reset the counter, then
 * update the MaxCounter after each iteration.
 *
 * Best Approch: T(n), S(n)
 * Store all the elements in unordered_set
 * Why set => (it removed the duplicate element),
 * Why unordered => (it takes constant tiem to find and insert),
 * -> Trick is:
 *      Traverse the Set, on each iteration maintain a count with initial value 1
 *      find if a previous element exists if yes then (it would be better to
 *      calculate length from previous element) skip this iteration.
 *      Else the previous element doesn't exist, then run a while loop untill
 *      we getting next consecutive element in array, keep increasing count.
 *      Finally compare with Max Count and update.
 */

class Solution
{
public:
    int longestConsecutiveOptimizedApproch(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }
        unordered_set<int> consecutive;
        int maxConsCount = 0;
        for (auto i : arr)
        {
            consecutive.insert(i);
        }
        for (auto i : consecutive)
        {
            int count = 1;
            if (consecutive.find(i - 1) == consecutive.end())
            {
                int j = i;
                while (consecutive.find(++j) != consecutive.end())
                {
                    count++;
                }
            }
            maxConsCount = max(maxConsCount, count);
        }
        return maxConsCount;
    }
    int longestConsecutiveSortedApproch(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }
        int maxConsCount = 0, consCount = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == 1)
            {
                consCount++;
            }
            else if (arr[i] == arr[i - 1])
            {
                continue;
            }
            else
            {
                consCount = 0;
            }
            maxConsCount = max(maxConsCount, consCount);
        }
        return maxConsCount + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << "Original array: ";
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;

    int result = sol.longestConsecutiveOptimizedApproch(arr);
    cout << "Length of the longest consecutive sequence: " << result << endl;

    return 0;
}