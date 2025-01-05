#include <iostream>
#include <string>
#include <climits>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 *
 * Optimized Approch: T(n) S(1)
 * We'll traverse the string and on encounter with '(' opening bracket we'll
 * increase depth by 1, else if its ')' closing bracket we'll decrease depth by 1
 * and on each iteration we'll keep track of maximum depth.
 */

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0, maxDepth = INT_MIN;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                depth++;
            else if (s[i] == ')')
                depth--;
            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};

int main()
{
    Solution solution;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Max Depth: " << solution.maxDepth(s) << endl;
    return 0;
}