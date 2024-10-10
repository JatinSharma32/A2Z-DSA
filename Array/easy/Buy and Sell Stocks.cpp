#include <iostream>
#include <vector>
using namespace std;

/**
 * Documentation below in code
 *
 * Optimized Approch: T(n), S(1)
 * Using Kadane's Algorithm
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /*
        Kadane's algorithm where we have to keep track of Max profit till now and
        Minimum Price of stock till now.
        */
        int currentPrice = 0, boughtPrice = 0, maxProfit = 0;
        // We will traverse every
        for (; currentPrice < prices.size(); currentPrice++)
        {
            // We have to keep the bought price Minimum
            if (prices[currentPrice] < prices[boughtPrice])
            {
                boughtPrice = currentPrice;
            }
            /*
            Calculate profit according to current Buy and Sell prices, if its maximum till
            now then update
            */
            int profit = prices[currentPrice] - prices[boughtPrice];
            if (profit > maxProfit)
                maxProfit = profit;
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}