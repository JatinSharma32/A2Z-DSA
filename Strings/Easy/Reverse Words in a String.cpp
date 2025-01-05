#include <iostream>
#include <string>
using namespace std;

/**
 * Problem statement:
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Optimized Approch: T(n) S(1)
 *
 * We'll traverse the string from the backwards, and keep adding characters in reverse
 * order to a temperorary string till a space is found.
 *
 * If the temperorary string is not empty, then we add that temperorary string to the
 * answer string, and empty the temperorary string.
 *
 * Finally when all the string is traversed then check if, temperorary string still have
 * something in it, if yes then add it into the result and finally return result.
 *
 *
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "", temp = "";
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (temp == "")
                {
                    continue;
                }
                // now add this "temp" word to result string
                if (result == "")
                {
                    result = temp;
                }
                else
                {
                    result = result + ' ' + temp;
                }
                temp = "";
            }
            else
            {
                // add this letter to temp
                temp = s[i] + temp;
            }
        }
        if (temp.size())
        {
            if (result == "")
            {
                result = temp;
            }
            else
            {
                result = result + ' ' + temp;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string input = "the sky is blue";
    string output = solution.reverseWords(input);
    cout << "Reversed words: " << output << endl;
    return 0;
}