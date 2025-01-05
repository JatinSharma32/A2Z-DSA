#include <iostream>
#include <queue>
#include <string>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/rotate-string/
 *
 * Optimized Approch: T(n^2), S(n) or S(2^n)
 * We'll put the both strings in 2 separate queues and on every iteration we pop and push
 * the element means we rotate the queue and every iteration we check if any rotation makes
 * them equal then return true otherwise false
 */

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        queue<char> sQ, goalQ;
        for (auto i : s)
        {
            sQ.push(i);
        }
        for (auto i : goal)
        {
            goalQ.push(i);
        }
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = sQ.front();
            sQ.pop();
            sQ.push(ch);
            if (sQ == goalQ)
            {
                return true;
            }
        }
        if (sQ == goalQ)
        {
            return true;
        }
        return false;
    }

    bool rotateStringMySolution(string s, string goal)
    {
        string sRotated = s;
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (sRotated == goal)
            {
                return true;
            }
            char ch = sRotated[0];
            sRotated = sRotated.substr(1, sRotated.size() - 1) + ch;
        }
        if (sRotated == goal)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    if (solution.rotateString(s, goal))
    {
        cout << "The string \"" << s << "\" can be rotated to become \"" << goal << "\"." << endl;
    }
    else
    {
        cout << "The string \"" << s << "\" cannot be rotated to become \"" << goal << "\"." << endl;
    }
    return 0;
}