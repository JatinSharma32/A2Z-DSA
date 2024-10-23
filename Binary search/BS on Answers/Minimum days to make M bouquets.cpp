#include <iostream>
#include <vector>
#include <algorithm> // For min_element and max_element
#include <climits>   // For INT_MAX
using namespace std;

/**
 * We have to make m Bouquets with k flowers each, we have to take
 * flowers from a row of n flowers, each flowers in row blooms on ith
 * day givenin array
 *
 * [1,10,3,10,2], m = 3, k = 1
 * OUTPUT => 3
 *
 * [1,10,3,10,2], m = 3, k = 2
 * OUTPUT => -1
 *
 * [7,7,7,7,12,7,7], m = 2, k = 3
 * OUTPUT => 12
 *
 * Brute Force: T( (max[bloomDay]-min[bloomDay]) * n ) S(1)
 * We will do linear search from min and max element of bloomDay on each element
 * we'll calculate the total number of days required complete m Bouquets with k
 * flowers each.
 *
 * Using a function fn(bloomDay, DaysWeHave )
 *  - Here we'll find how many Bouquets can be made within NoOfDaysWeHave.
 *  - Here we have to find the consicutive 'k' flowers ready on NoOfDaysWeHave.
 *
 * If any element between min and max of bloomDay gives total Bouquets more then
 * or equal to m bananas thats our answer.
 *
 *
 * Optimized Approch: T( log(max[bloomDay]-min[bloomDay]) * n) S(1)
 * Just convert the linear search to Binary search in 1st step
 *
 *             => Comments are in code for better understanding.
 */

class Solution
{
public:
    int noOfBouquets(vector<int> &bloomDay, int i, int k, int n)
    {
        int ct = 0, Gct = 0;
        for (int p = 0; p < n; p++)
        {
            if (bloomDay[p] > i)
            {
                ct = 0;
            }
            else
            {
                ct++;
            }
            if (ct >= k)
            {
                Gct++;
                ct = 0;
            }
        }
        return Gct;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if ((n / k) < m)
        {
            return -1;
        }
        if (n == 1)
        {
            return bloomDay[0];
        }
        int l = *(min_element(bloomDay.begin(), bloomDay.end()));
        int h = *(max_element(bloomDay.begin(), bloomDay.end()));

        int minDay = INT_MAX;
        while (l <= h)
        {
            int i = (l + h) / 2;
            if (noOfBouquets(bloomDay, i, k, n) >= m)
            {
                // we have enough noOfBouquets so check if some less are available;
                minDay = min(minDay, i);
                h = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
        return minDay;
    }
};

int main()
{
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2}; // Example input
    int m = 3;                                // Example number of bouquets
    int k = 1;                                // Example number of flowers per bouquet

    cout << "Bloom days: ";
    for (int val : bloomDay)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.minDays(bloomDay, m, k);

    if (result != -1)
    {
        cout << "Minimum number of days to make " << m << " bouquets: " << result << endl;
    }
    else
    {
        cout << "It is not possible to make " << m << " bouquets." << endl;
    }

    return 0;
}