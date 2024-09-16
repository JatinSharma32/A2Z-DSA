#include <iostream>
#include <vector>
using namespace std;

/**
 * Documentation not needed
 */

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &arr)
    {
        vector<int> result(arr.size());
        int i = 0, j = 1;
        for (auto e : arr)
        {
            if (e >= 0)
            {
                result[i] = e;
                i += 2;
            }
            else
            {
                result[j] = e;
                j += 2;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31};

    cout << "Original array: ";
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;

    vector<int> result = sol.rearrangeArray(arr);

    cout << "Rearranged array: ";
    for (auto p : result)
    {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}