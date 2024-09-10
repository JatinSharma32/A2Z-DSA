#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Docs Pending
 * Dutch National Flag Algorithm
 */

class Solution
{
public:
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