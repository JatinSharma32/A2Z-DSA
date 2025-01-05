#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/longest-common-prefix/
 *
 * Optimized approch: T(n*m) S(1)
 * We'll take the 1st element as the result (common prefix) and then traverse the whole
 * array of strings, on each iteration we'll compare result with a string, so we know
 * the longest common prefix between them in best case could be the smaller string
 *
 *                          min(result, strs[i])
 *
 * So we'll store that index in 'i', it will tell us that prefix is between [0 to index]
 * in 1st string.
 * Then we'll compare each character of both strings from 0 to min(result, strs[i])
 * and stop when the character miss matches and store min of 'i' & that index in 'i'.
 * Finally return the substring of strs[0] from 0 to i.
 *
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string s = strs[0];
        int index = INT_MAX;
        for (auto i : strs)
        {
            int m = min(i.size(), s.size());
            index = min(index, m);
            for (auto j = 0; j < m; j++)
            {
                if (i[j] != s[j])
                {
                    index = min(index, j);
                    break;
                }
            }
        }
        return s.substr(0, index);
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;
    return 0;
}