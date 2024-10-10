#include <iostream>
#include <vector>
using namespace std;

/**
 *
- ye question same hai Count Inversion ki tereh bas iss mai count kerne hai
- vo vale pairs jo ki i<j and a[i]>2*a[j], bas iss mai twice bade dhundh ne hai

- Pichli approch mai hum count and merge sort ek sath ker rehe the same
- loop mai the per vo approch yahan work nahi kerega because of the case
- suppose

        -> use this example to understand.
            [2  3  4]       [1  5]

             [     new Array    ]

- Kyoki iss case mai 2 - 1 se bada hai ofcourse to merge sort (a[j] ko new
- array mai dalna and j++) to hogi per count vali operations nahi hogi
- per j to aage badh gaya iss chakker se 3, 4 jo ki 2*1 se bade hai vo miss
- ho jayege so thats why



                    hume merge sort and Count k alag alag loops mai kerna hoga
                    and it works fine.

 */

class Solution
{
public:
    int modifiedMerge(vector<int> &arr, int s, int m, int e)
    {
        vector<int> nv;
        int i = s, j = m + 1, count = 0;
        // this loop for counting
        while (i <= m && j <= e)
        {
            long long a = 2 * (long long)arr[j];
            long long b = arr[i];
            if (b > a)
            {
                count = count + m - i + 1;
                j++;
            }
            else
            {
                i++;
            }
        }
        i = s;
        j = m + 1;
        // this loop for merging operations
        while (i <= m && j <= e)
        {
            if (arr[i] > arr[j])
            {
                nv.push_back(arr[j]);
                j++;
            }
            else
            {
                nv.push_back(arr[i]);
                i++;
            }
        }
        while (i <= m)
        {
            nv.push_back(arr[i++]);
        }
        while (j <= e)
        {
            nv.push_back(arr[j++]);
        }
        i = 0;
        for (int k = s; k <= e; k++)
        {
            arr[k] = nv[i++];
        }
        return count;
    }

    int mergeSort(vector<int> &arr, int s, int e)
    {
        if (s >= e)
        {
            return 0;
        }
        int mid = (e + s) / 2, count = 0;
        count += mergeSort(arr, s, mid);
        count += mergeSort(arr, mid + 1, e);
        count += modifiedMerge(arr, s, mid, e);
        return count;
    }

    int reversePairs(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 2, 3, 1}; // Example input

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.reversePairs(arr);

    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}