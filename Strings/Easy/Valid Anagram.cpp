#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/valid-anagram
 *
 *
 * Better Approch: T(nlogn), S(1)
 * Sort both Strings and check if they are equal then they are anagrams return true,
 * else false.
 *
 * Optimized Approch: T(n), S(2*n)
 * Use 2 seperate maps to store characters with their frequency in strings then
 * compare each character's frequency in both map, if all are equal then return true
 * Its anagram, otherwise return false.
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> sM, tM;
        for (int i = 0; i < s.size(); i++)
        {
            sM[s[i]]++;
            tM[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (sM[s[i]] != tM[s[i]])
            {
                return false;
            }
        }
        return true;
    }
    bool isAnagramSorting(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    if (solution.isAnagram(s, t))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}