#include <iostream>
#include <string>
using namespace std;

/**
 * Read from
 * https://leetcode.com/problems/remove-outermost-parentheses/
 *
 * Optimized approch:
 * We'll have a count variable initilized to 0, it increases as bracket opens '('
 * and decreases as bracket closes ')'
 * we will use it to identify the outer most brackets like...
 *      => If count is less then 1 then we are on the outer most opening bracket.
 *      => OR
 *      => If Count is 1 also s[i] is closing bracket means we are on outer most
 *         closing bracket.
 *
 * Now we traverse whole string and copy each character into new string, while skiping
 * outermost brackets.
 *
 */

class Solution
{
public:
    string removeOuterParenthesesOptimized(string s)
    {
        string ans;
        int ct = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (ct > 1 || (ct == 1 && s[i] == '('))
            {
                ans += s[i];
            }
            if (s[i] == '(')
                ct++;
            else
                ct--;
        }
        return ans;
    }
    string removeOuterParentheses(string s)
    {
        string ans;
        int i = 0, count = 0, indx = 0;
        while (i < s.size())
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            if (count == 0)
            {
                ans += s.substr(indx + 1, i - indx - 1);
                indx = i + 1;
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string input = "(()())(())";
    string result = solution.removeOuterParentheses(input);
    cout << "Result: " << result << endl;
    return 0;
}