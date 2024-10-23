#include <iostream>
#include <cmath> // For pow function
using namespace std;

/**
 * Find floor of Pth root of "n" in log n time.
 *
 * Brute force: T(n) S(1)
 * We can run a linear search from 1 to n, and check for the number
 * that gives floor of Pth root of "n", like for (5 => 2),(4 => 2).
 *
 * Optimized Approch: T(logn) S(1)
 * We can convert this linear search to Binary Search, and calculate
 * the (mid ^ P)
 *  => if its equal to "n" then return mid.
 *  => if its greater, then eliminate right half h=m-1.
 *  => if its smaller, then eliminate left half l=m+1.
 * Finally if nothing is found then return -1;
 */

class Solution
{
public:
    int NthRoot(int p, int n)
    {
        long long l = 1, h;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        h = (n / p);
        while (l <= h)
        {
            long long mid = (l + h) / 2;
            long long midPow = pow(mid, p);
            if (midPow == n)
            {
                return (int)mid;
            }
            if (midPow > n)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int p = 3;  // Example input for power
    int n = 27; // Example input for number

    cout << "Finding " << p << "th root of " << n << endl;

    int result = sol.NthRoot(p, n);

    if (result != -1)
    {
        cout << p << "th root of " << n << " is: " << result << endl;
    }
    else
    {
        cout << p << "th root of " << n << " does not exist as an integer." << endl;
    }

    return 0;
}