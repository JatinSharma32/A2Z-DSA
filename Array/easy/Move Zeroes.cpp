#include <bits/stdc++.h>
using namespace std;

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