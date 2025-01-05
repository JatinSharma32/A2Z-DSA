#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/sort-characters-by-frequency/
 *
 * Optimized Approch (Sorting):
 * PENDING
 */

class Solution
{
public:
    string frequencySort(string s)
    {
        string result;
        map<char, int> freq;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }

        // Convert map to vector of pairs for sorting
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Sort using a lambda function
        sort(freqVec.begin(), freqVec.end(),
             [](pair<char, int> &prev, pair<char, int> &next)
             {
                 return prev.second > next.second;
             });

        for (auto i : freqVec)
        {
            while ((i.second--) > 0)
            {
                result += (i.first);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: "eert" or "eetr"
    return 0;
}