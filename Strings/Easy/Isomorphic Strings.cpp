#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * We are given 2 strings "s" and "t" of same size, and we have to tell weather
 * these 2 strings are Isomorphic or not:
 *      => every charater of "s" can be replaced to a character of "t"
 *      => No 2 characters can be replaced by a same character.
 *      => And finally the order of characters can't be changed.
 *
 *      Example: s = "foo", t = "bar"
 *               here 'o' is getting replaced by 'a' and 'r' both so
 *               "s" and "t" are not Isomorphic strings.
 *
 * Optimized approch: T(n) S(2n)
 * Basic solution that comes to our mind for this problem is that
 * suppose in "s" a character is present 5 times so there must hace to be a character that
 * appears exactly 5 times in "t".
 * So basically there should be 2 elements in "s" and "t" which appears exactly same times.
 * and can be replaced.
 *
 * We'll use 2 Maps to implement this solution one for storing "s"->"t", other
 * for "t"->"s".
 * Traverse i'th elements of "s" and "t" together, and check if
 *      => ith element of "s" is already mapped to another element of "t"
 *      => ith element of "t" is already mapped to another element of "s"
 *              => In both of these cases return false
 *      => Other wise put "s"and "t"s i'th characters into maps.
 *
 */

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> StoTRep, TtoSRep;
        int n = s.size();
        if (n != t.size())
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (StoTRep[s[i]] != 0 && StoTRep[s[i]] != t[i])
                return false;
            if (TtoSRep[t[i]] != 0 && TtoSRep[t[i]] != s[i])
                return false;
            StoTRep[s[i]] = t[i];
            TtoSRep[t[i]] = s[i];
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "egg"; // Example input
    string t = "add"; // Example input

    cout << "String s: " << s << endl;
    cout << "String t: " << t << endl;

    bool result = sol.isIsomorphic(s, t);

    if (result)
    {
        cout << "The strings \"" << s << "\" and \"" << t << "\" are isomorphic." << endl;
    }
    else
    {
        cout << "The strings \"" << s << "\" and \"" << t << "\" are not isomorphic." << endl;
    }

    return 0;
}