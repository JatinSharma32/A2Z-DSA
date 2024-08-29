#include <bits/stdc++.h>
using namespace std;

/**
 * Move Zeros to the end
 * [0,1,0,3,12] to [1,3,12,0,0]
 *
 *              Brute force: T(n^2), S(1)
 * We traverse array in backward from [n-2 , 0],
 * when we find 0 -> swap it with next element, till we next element zero or Array ends
 *
 *              Optimal approch: T(n), S(1)
 * INPLACE - What if we move all the Non Zero elements to start and then add zeros at
 * remaining positions, could be done in Linear Complexity
 * Traverse through the array [0 , n-1] with pointer i
 * And keep a pointer j at zero and increase only when found an Non zero element
 * Put that Non Zero Element at j index and increase it.
 * Finally put 0 in array from [j , n-1]
 *
 */

class Solution
{
public:
    void moveZeroes(vector<int> &arr)
    {
        int n = arr.size();
        int ctr = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                arr[ctr++] = arr[i];
            }
        }
        for (; ctr < n; ctr++)
        {
            arr[ctr] = 0;
        }
    }
};

void printArray(vector<int> &v, string s)
{
    cout << s + ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    Solution s;
    s.moveZeroes(arr);
    printArray(arr, "Result");
    return 0;
}