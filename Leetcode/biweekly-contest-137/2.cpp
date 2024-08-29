#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v, string s)
{
    cout << s + ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

class Solution
{
public:
    vector<int> resultArray(vector<int> &v, int k)
    {
        // Make adjecent difference array
        vector<int> adjecentDiff, result;
        int vSize = v.size();
        if (k == 1 || vSize == 1)
        {
            return v;
        }
        for (int i = 1; i < vSize; i++)
        {
            adjecentDiff.push_back(v[i] - v[i - 1]);
        }
        printArray(adjecentDiff, "Adjecent Difference");

        // In adjecentDiff find k-1 sequences of 1
        int count = 0, ADsize = adjecentDiff.size();
        for (int i = 0; i < ADsize; i++)
        {
            if (adjecentDiff[i] == 1)
            {
                count++;
            }
            else if (count > 0)
            {
                count = 0;
            }
            if (i + 1 >= k - 1)
            {

                if (count >= k - 1)
                {
                    // current i mai +1
                    result.push_back(v[i + 1]);
                }
                else if (count < k - 1)
                {
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};

int main()
{
    int n, i, k;
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    Solution s;
    auto v = s.resultArray(arr, k);
    printArray(v, "Result");
    return 0;
}