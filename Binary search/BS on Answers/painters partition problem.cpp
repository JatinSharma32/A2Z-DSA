#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 * Description read from:
 * https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
 *
 * Brute force: T( n * ( sumOfArray - maxOfArray )), S(1)
 * We have the range (Max of Array to Sum of Array) between which our answer will lie
 * so we'll apply linear search on this range to check for how low the max time can go.
 *
 * We'll use NoOfPainters function to find how many Painters will be needed to paint
 * all boards, while paint area limit for each painter being there. It works as:
 * We'll keep giving a board to a Painter till that it is not hitting the max
 * paint limit, if it hits then stop giving board to current painter, and start with
 * new painter. FINALLY RETURN HOW MANY PAINTERS ARE NEEDED FOR THIS MAX LIMIT.
 *
 * Optimized Approch: T(n * log(sumOfArray - maxOfArray) ), S(1)
 * We'll just apply Binary search at the place Linear search.
 *
 *    Board with  ----------------------|-----------------------  Sum of all
 *     max area                        Mid                        boards Area
 *                     <-----                      ----->
 *                No of painters               No of painters
 *                   Increases                   decreases
 */

int NoOfPainters(vector<int> &boards, int maxArea)
{
    int painters = 1, coveredArea = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (coveredArea + boards[i] > maxArea)
        {
            painters++;
            coveredArea = boards[i];
        }
        else
        {
            coveredArea += boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    // Edge cases afterwards
    int l = *(max_element(boards.begin(), boards.end()));
    int h = accumulate(boards.begin(), boards.end(), 0);
    int ans;
    while (l <= h)
    {
        int m = (l + h) / 2;
        int painters = NoOfPainters(boards, m);
        if (painters <= k)
        {
            ans = m;
            h = m - 1;
        }
        else if (painters > k)
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40}; // Example input
    int k = 2;                             // Number of painters
    int result = findLargestMinDistance(boards, k);
    cout << "Largest minimum distance: " << result << endl;
    return 0;
}