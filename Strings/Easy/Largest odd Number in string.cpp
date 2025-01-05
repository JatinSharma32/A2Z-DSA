#include <iostream>
using namespace std;

/**
 * Self-explanatory
 * https://leetcode.com/problems/largest-odd-number-in-string/
 */

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int i = num.size() - 1;
        for (; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{
    Solution solution;
    string num;
    cout << "Enter a number: ";
    cin >> num;
    string result = solution.largestOddNumber(num);
    if (result.empty())
    {
        cout << "No odd number found in the string." << endl;
    }
    else
    {
        cout << "The largest odd number in the string is: " << result << endl;
    }
    return 0;
}
