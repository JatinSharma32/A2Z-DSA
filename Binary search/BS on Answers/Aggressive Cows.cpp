#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

/**
 * Description read from:
 * https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
 *
 * Brute force: T( n * ( maxOfArray-minOfArray to 1 )), S(1)
 * We have the range ((Max of Array - Min of Array) to 1) between which our answer will lie
 * so we'll apply linear search on this range to check for how high the min distances between
 * 2 cows can be, the highest will be our answer.
 *
 * We'll use NoOfCows function to find how many cows can be allocated books with
 * that min distance limit being there. It works as:
 * We'll keep skipping stalls till 2 cows have more or equal distance between them
 * with respect to minimum distance, if distance is more then min distance then increase
 * the cow number.
 * Finally return how many cows have been allocated.
 *
 * Optimized Approch: T(n * log(sumOfArray - maxOfArray) ), S(1)
 * We'll just apply Binary search at the place Linear search.
 *
 *    1 ----------------------|------------------------- maxOfArray-minOfArray
 *                           Mid
 *             <-----                      ----->
 *           No of cows                  No of cows
 *            Increases                   Decreases
 *
 */

int NoOfCows(vector<int> &stalls, int minDistance)
{
    int cow = 1, dist = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - dist >= minDistance)
        {
            cow++;
            dist = stalls[i];
        }
    }
    return cow;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int l = 1;
    int h = stalls[stalls.size() - 1] - stalls[0];
    int ans;
    while (l <= h)
    {
        int m = (l + h) / 2;
        int cows = NoOfCows(stalls, m);
        if (cows >= k)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example input
    int k = 3;                            // Example number of cows

    cout << "Stalls: ";
    for (int val : stalls)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = aggressiveCows(stalls, k);

    cout << "Largest minimum distance between cows: " << result << endl;

    return 0;
}