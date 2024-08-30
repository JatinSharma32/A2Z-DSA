#include <bits/stdc++.h>
using namespace std;

/**
 * Find Union
 * Find the Union of 2 sorted arrays, maintain sorting and remove duplicates
 * even if in same array
 * {1, 2, 2, 3, 4, 5} & {1, 2, 3, 6, 7} to {1, 2, 3, 4, 5, 6, 7}
 *
 * Brute force: T(n+m), S(n+m)
 * Make a set of ints, insert 1st arrays elements and then 2nd arrays elements.
 *
 * Optimized approch: T(n+m), S(1)
 * Take 2 pointers i and j for both arrays starting from 0 index in both arrays
 * find the smaller element on both pointers in both arrays,
 * ignore if that is already in union array, otherwise push
 * Do it untill any of the array ends, finally repeat these steps on remaining elements
 * if any left in any array.
 *
 */

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> uin;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                if (uin.size() == 0 || arr1[i] != uin.back())
                {
                    uin.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if (uin.size() == 0 || arr2[j] != uin.back())
                {
                    uin.push_back(arr2[j]);
                }
                j++;
            }
        }
        while (i < n)
        {
            if (uin.size() == 0 || arr1[i] != uin.back())
            {
                uin.push_back(arr1[i++]);
            };
        }
        while (j < m)
        {
            if (uin.size() == 0 || arr2[j] != uin.back())
            {
                uin.push_back(arr2[j++]);
            };
        }
        return uin;
    }
};

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}