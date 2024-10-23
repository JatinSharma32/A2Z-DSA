#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

/**
 * We have a Ship and we have to port all the packages given in list in 'd' days
 * Return the minimum weight capacity of ship, to port all the packages in 'd' days
 *
 * [1,2,3,4,5,6,7,8,9,10], d = 5
 * OUTPUT => 15
 *
 * [3,2,2,4,1,4], d = 3
 * OUTPUT => 6
 *
 * Brute Force: T( (sumOfAll[weight]-max[weight]) * n ) S(1)
 * We will do linear search from max element of weight to sum of all elements, on each
 * element we'll calculate the total number of days required to port all packages with
 * ship's max capacity 'c'.
 *
 * Using a function fn(weight, ShipCapacity )
 *  - Here we have to find the total no of days it takes to ship a package in sets.
 *
 * If any element between max element of weight to sum of all elements, gives total
 * Days less then or equal to d thats our answer.
 *
 * Optimized Approch: T( log(sumOfAll[weight]-max[weight]) * n) S(1)
 * Just convert the linear search to Binary search in 1st step
 *
 *             => Comments are in code for better understanding.
 */

class Solution
{
public:
    int totalDays(vector<int> &weights, int c)
    {
        int days = 0, sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (sum == c)
            {
                days++;
                sum = 0;
            }
            else if (sum > c)
            {
                days++;
                sum = weights[i];
            }
        }
        if (sum)
        {
            days++;
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int h = 0, l = INT_MIN;
        for (auto i : weights)
        {
            h += i;
            l = max(l, i);
        }
        int minLoad = INT_MAX;
        while (l <= h)
        {
            int m = (l + h) / 2;
            int Tdays = totalDays(weights, m);
            if (Tdays <= days)
            {
                h = m - 1;
                minLoad = min(minLoad, m);
            }
            else
            {
                l = m + 1;
            }
        }
        return minLoad;
    }
};

int main()
{
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example input
    int days = 5;                                          // Example number of days

    cout << "Weights: ";
    for (int val : weights)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.shipWithinDays(weights, days);

    cout << "Minimum capacity to ship within " << days << " days is: " << result << endl;

    return 0;
}