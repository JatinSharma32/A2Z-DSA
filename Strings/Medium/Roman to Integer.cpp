#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Problem Statement
 * https://leetcode.com/problems/roman-to-integer/
 *
 * Omtimized Approch: T(n) S(1)
 * We'll create a constant sized Map for Roman characters to their values
 * Then we'll traverse the string in reverse and check 2 elements together, if
 * current element is smaller then next then substract it from result.
 * else if its equal of greater then add it to result.
 * finally return Result.
 */

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int result = m[s[s.size() - 1]];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (m[s[i]] >= m[s[i + 1]])
            {
                result += m[s[i]];
            }
            else
            {
                result -= m[s[i]];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string roman = "MCMXCIV"; // Example input
    int result = solution.romanToInt(roman);
    cout << "The integer value of " << roman << " is " << result << endl;
    return 0;
}