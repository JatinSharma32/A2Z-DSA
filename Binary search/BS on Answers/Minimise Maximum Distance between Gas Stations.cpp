#include <iostream>
#include <vector>
#include <cmath> // For pow function
using namespace std;

/**
 * Read Problem from
 * https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/
 *
 * -------------- Read Binary search on FLOATS and DOUBLES in notes. ----------------
 *
 * Optimized Approch: T(n*Log(max of array - min of array)), S(1)
 * We have the range (Zero to Max of Array - Min of Array) between which our answer will
 * lie so we'll apply Binary Search on this range to check for how low the max Distance
 * can go between any 2 gas stations.
 *
 * { NOTE: We'll not put Gas stations beyond the ends of Array, as putting new stations
 * there will not affect or minimize the existing gas stations distances. }
 *
 * We'll use NoOfGasStations function to find how many Gas Stations will be needed to
 * maintain the max distance between all the Stations. It works as:
 * We'll keep checking the distance between 2 adjecent gas stations if its found more then
 * Max distance then we'll put n number of stations between existing Gas stations to reduce
 * the distance between them till Max Distance. HOW?
 * We'll divide the distance b/w adjecent stations to the max distance needed, it will give
 * the number of new stations needed needed to maintain the max distance. If there would be
 * no reminder then we'll reduce 1 from the new Gas stations being added.
 * FINALLY RETURN HOW MANY STATIONS ARE NEEDED TO MAINTAIN THIS MAX DISTANCE.
 *
 *    0 ----------------------|----------------------- Max - Min
 *                           Mid                       Of array
 *            <-----                       ----->
 *        No of Stations               No of Stations
 *           Increases                   Decreases
 */

int NoOfGS(vector<int> &arr, double maxDist)
{
    int GS = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] > maxDist)
        {
            // put GS here How many?
            int temp = (arr[i] - arr[i - 1]) / maxDist;
            if ((arr[i] - arr[i - 1]) == temp * maxDist)
            {
                temp--;
            }
            GS += temp;
        }
    }
    return GS;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    double l = 0, h = arr[n - 1] - arr[0];
    double ans, lim = pow(10, -6);
    while (h - l > lim)
    {
        double mid = (l + h) / 2;
        int GS = NoOfGS(arr, mid);
        if (GS <= k)
        {
            ans = mid;
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 7, 9}; // Example input
    int k = 2;                            // Example number of gas stations

    cout << "Gas stations: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    double result = minimiseMaxDistance(arr, k);

    cout << "Minimum maximum distance between gas stations: " << result << endl;

    return 0;
}