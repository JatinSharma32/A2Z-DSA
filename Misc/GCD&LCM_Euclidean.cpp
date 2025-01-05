#include <bits/stdc++.h>
using namespace std;

/**
 * Euclidean Algorithm:https://youtu.be/1xNbjMdbjug?si=HYDI9UQLtyKbuTzO&t=3169
 * Explained in above video
 *
 * Basically its long division so the GCD of (a,b) is equal to GCD of (a-b,b)
 * so we keep dividing a%b => b%(a%b) => till the reminder comes zero
 * that is our GCD
 */

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a % b == 0)
        {
            return b;
        }
        int rem = a % b;
        gcd(b, rem);
    }
    vector<int> lcmAndGcd(int a, int b)
    {
        int g = gcd(max(a, b), min(a, b));
        int l = a * b / g;
        return {l, g};
    }
};
int main()
{
    Solution sol;
    int a = 12, b = 18;
    vector<int> result = sol.lcmAndGcd(a, b);
    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
    return 0;
}