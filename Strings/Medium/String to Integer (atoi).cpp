#include <iostream>
#include <string>
#include <climits>

/**
 * Problem Statement
 * https://leetcode.com/problems/string-to-integer-atoi/
 *
 * Optimized Approch: T(n), S(1)
 * We will 1st skip all the whitespaces in front
 *
 * Then find if current character is a sign and update the sign accordingly 1 or -1
 *
 * Then skip zeros till 1 to nine is found, if some other character is there then return 0
 *
 * Then after skipping all the zeros, we start taking the integers till a non numeric
 * character is found, if result crosses the limits then return the limit.
 */

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.size();
        // skip white spaces
        while (s[i] == ' ')
        {
            i++;
        }

        // find sign
        int sign = 1;
        if (s[i] == '-')
        {
            i++;
            sign = -1;
        }
        else if (s[i] == '+')
        {
            i++;
            sign = 1;
        }

        // skip zeros
        for (; i < n; i++)
        {
            if (s[i] == '0')
                continue;
            if (s[i] >= '1' && s[i] <= '9')
            {
                break;
            }
            else
                return 0;
        }

        long long result = 0;
        // now read the characters from i to j-1
        for (; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                result = (result * 10) + (int)(s[i] - '0');
                if (result * sign > INT_MAX)
                {
                    return INT_MAX;
                }
                else if (result * sign < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
                break;
        }
        result *= sign;

        return (int)result;
    }
};

int main()
{
    Solution solution;
    string str = "   -42";
    cout << solution.myAtoi(str) << endl; // Output: -42

    str = "4193 with words";
    cout << solution.myAtoi(str) << endl; // Output: 4193

    str = "words and 987";
    cout << solution.myAtoi(str) << endl; // Output: 0

    str = "-91283472332";
    cout << solution.myAtoi(str) << endl; // Output: -2147483648 (INT_MIN)

    return 0;
}