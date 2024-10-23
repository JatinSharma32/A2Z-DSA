#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <climits>   // For INT_MAX
using namespace std;

/**
 * We have to find the minimum number of Banana need to be eaten per hour
 * to finish all of them till "h" hours
 * There are "n" piles,
 * [3,6,7,11], h = 8
 * OUTPUT => 4
 *
 * [30,11,23,4,20], h = 5
 * OUTPUT => 30
 *
 * [30,11,23,4,20], h = 6
 * OUTPUT => 23
 *
 * Brute Force: T( max[piles] * n ) S(1)
 * We will do linear search from 1 to max element of Pile on each element
 * we'll calculate the total hours it takes to complete all of the bananas
 *
 * Using a function fn(Piles, NoOfBananasperHour)
 *  - Here we have to find the sum of hours takes by each pile
 *  - Hour taken by a pile is ciel of division of pile[i] by no of bananas.
 *
 * If any element between 1 to max of piles gives total hours for k bananas
 * per hour gives equal of close to h hours thats our answer.
 *
 * Optimized Approch: T( log(max[piles]) * n) S(1)
 * Just convert the linear search to Binary search in 1st step
 *
 *             => Comments are in code for better understanding.
 */

class Solution
{
public:
    long long totalHoursForBananasPerHour(vector<int> &piles, int k)
    {
        long long totalHours = 0;
        for (auto i : piles)
        {
            // ceil of i/k.
            int hoursForThisPile = (i / k) + ((i % k == 0) ? 0 : 1);
            totalHours += hoursForThisPile;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int> &piles, int hr)
    {
        // check edge cases afterwards
        int l = 1, h = *(max_element(piles.begin(), piles.end()));
        // also make a global min for answer
        int ans = INT_MAX;
        // Now this was our range
        // apply BS on it

        // LOWER BOUND
        while (l <= h)
        {
            int m = l + ((h - l) / 2);
            long long hoursForK = totalHoursForBananasPerHour(piles, m);
            if (hoursForK <= hr)
            {
                // it means monkey is eating sufficient or enough bananas to complete all
                // of them before h hours.
                // so check if there also exist some low value of m for which all bananas
                // can be eaten so eliminate the right half;
                ans = min(ans, m);
                h = m - 1;
            }
            else
            {
                // It means monkey is eating too few bananas that he can't complete it all
                // before h hours so increase the bananas.
                l = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {3, 6, 7, 11}; // Example input
    int hr = 8;                        // Example hours

    cout << "Piles: ";
    for (int val : piles)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.minEatingSpeed(piles, hr);

    cout << "Minimum eating speed to finish all bananas in " << hr << " hours is: " << result << endl;

    return 0;
}