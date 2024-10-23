#include <iostream>
using namespace std;

/**
 * Find floor of square root of "n" in log n time.
 *
 * Brute force: T(n) S(1)
 * We can run a linear search from 1 to n, and check for the number
 * that gives floor of Sqr root of "n", like for (5 => 2),(4 => 2).
 *
 * Optimized Approch: T(logn) S(1)
 * We can convert this linear search to Binary Search, and calculate
 * the sqr of mid
 *  => if its equal to "n" then return mid.
 *  => if its greater, then eliminate right half h=m-1.
 *  => if its smaller, then eliminate left half l=m+1, while keeping track
 *     of this mid too as it can be floor, and return it at the end.
 */

class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        long long l = 1, h = n, sqr = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        while (l <= h)
        {
            long long mid = (l + h) / 2;
            if (mid * mid == n)
            {
                return mid;
            }
            if (mid * mid > n)
            {
                h = mid - 1;
            }
            else
            {
                sqr = max(sqr, mid);
                l = mid + 1;
            }
        }
        return sqr;
    }
};

int main()
{
    Solution sol;
    long long int n = 16; // Example input

    cout << "Number: " << n << endl;

    long long int result = sol.floorSqrt(n);

    cout << "Floor square root of " << n << " is: " << result << endl;

    return 0;
}