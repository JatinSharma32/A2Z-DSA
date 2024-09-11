#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Sort an array of 0s, 1s and 2s in a single pass using no extra space.
 *
 * Brute Force: T(n.logn), S(n)
 * Using sorting algorithms.
 *
 * Better Approch: T(2n), S(1)     ---     Not In place Sorting
 * Take 3 variables for each 0, 1 and 2 traverse throughtout
 * and update counts on the manually over write array with those counts
 *
 * Optimized Approch: T(n), S(1)
 *          DUTCH NATIONAL FLAG
 * In this algo we take 3 pointers low, mid and high
 * they shoud be potioned in such a way that
 *      -> all 0s are in {0, low}
 *      -> all 1s are in {low + 1, mid}
 *      -> unsorted elements is in {mid + 1, high}
 *      -> all 2s are in {high + 1, n}
 * Initially we keep low and mid at start 0 and high at end n.
 * Now start moving mid untill it crosses high, now If Current element
 *      -> is 0 then swap it with low and increase low & mid.
 *      -> is 1 then increase mid
 *      -> is 2 then swap it with high and decrease high.
 *
 */

class Solution
{
public:
    void DNF(vector<int> &arr)
    {
        int low = -1, mid = 0, n = arr.size();
        int high = n;
        while (mid < high)
        {
            if (arr[mid] == 0)
            {
                int temp = arr[mid];
                arr[mid++] = arr[++low];
                arr[low] = temp;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                int temp = arr[mid];
                arr[mid] = arr[--high];
                arr[high] = temp;
            }
        }
    }

    void sortColors(vector<int> &v)
    {
        unordered_map<int, int> counts = {{0, 0}, {1, 0}, {2, 0}};

        for (auto i : v)
        {
            counts[i]++;
        }
        int i = 0;
        while (counts[0] > 0)
        {
            v[i++] = 0;
            counts[0]--;
        }
        while (counts[1] > 0)
        {
            v[i++] = 1;
            counts[1]--;
        }
        while (counts[2] > 0)
        {
            v[i++] = 2;
            counts[2]--;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sol.sortColors(v);
    cout << "Sorted array: ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}