#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

/**
 * Given 2 sorted arrays we have to sort them with out extra space and return
 * in suach a way that first n elements are in one array and remainting in other
 *
 * [1 4 8 10], [2 3 9] ==(OUTPUT)==> [1 2 3 4], [8 9 10]
 *
 * Brute Force: T(n+m) S(n+m)
 * Make another array of size n+m and use 2 pointer approch of merge sort to sort.
 *
 * Optimized Approch: T(n.logn) S(1)
 * 2 Pointer approch is used, we know that all the largest elements are need to
 * be in 2nd array, so we can compare the smallest elements if 2nd array with
 * largest elements of 1st array.
 *  => If 1st array's largest element is larger then 2nd array's smallest then swap
 *     them and reduce the largest element pointer one place in 1st array,
 *     and increase smallest element pointer in 2nd array one place.
 *  => Otherwise the largest element of 1st array is not grater then smallest
 *     element of 2nd array.
 * Till this step we have all the n smallest element in 1st array and remaining
 * larger elements in 2nd array
 * Finally, sort them both
 */

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size() - 1, m = b.size();
    for (int i = 0; i < m; i++)
    {
        if (a[n] <= b[i])
        {
            break;
        }
        swap(a[n--], b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void mergeTwoSortedArraysWithoutExtraSpaceSHELLSORT(vector<long long> &a, vector<long long> &b)
{
    int n = a.size(), m = b.size();
    // Take ciel value
    int gap = ((n + m) / 2) + ((n + m) % 2);
    while (gap > 0)
    {
        for (int i = 0, j = gap; j < m + n; j++, i++)
        {
            if (i < n && j >= n)
            {
                if (a[i] > b[j - n])
                {
                    swap(a[i], b[j - n]);
                }
            }
            else if (i < n && j < n)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
            }
            else
            {
                if (b[i - n] > b[j - n])
                {
                    swap(b[i - n], b[j - n]);
                }
            }
        }
        if (gap == 1)
        {
            return;
        }
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    vector<long long> a = {1, 3, 5, 7};
    vector<long long> b = {2, 4, 6, 8};

    cout << "Original arrays:" << endl;
    cout << "a: ";
    for (long long val : a)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "b: ";
    for (long long val : b)
    {
        cout << val << " ";
    }
    cout << endl;

    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    cout << "Merged arrays:" << endl;
    cout << "a: ";
    for (long long val : a)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "b: ";
    for (long long val : b)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}