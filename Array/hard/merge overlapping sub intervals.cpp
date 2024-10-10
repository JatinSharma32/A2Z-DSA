#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

/**
 * Merge overlapping subintervals, return the array with no overlapping intrervals
 * [[1,3],[2,6],[8,10],[15,18]]
 *
 * Optimized Approch: T(n) S(n)
 * We will sort the intervals array, to bring up all intervals in Ascending order
 * Now we will make a Result Array of Intervals and traverse the array, for each
 * element we check
 *      => if its lover limit is "<=" then the Result's Last intervels
 *         end limit then it can be merged for update the result's Last
 *         intervals end limit with maximum of both intrvals
 *      => Else just push the interval into result array.
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        vector<vector<int>> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++)
        {
            auto &p1 = result.back(), &p2 = intervals[i];
            if (p1[1] >= p2[0])
            {
                int e = max(p1[1], p2[1]);
                int s = min(p1[0], p2[0]);
                p1 = {s, e};
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "Original intervals: ";
    for (const auto &interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged intervals: ";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}