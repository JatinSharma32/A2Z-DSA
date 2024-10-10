#include <iostream>
#include <vector>
using namespace std;

/**
 * Find number of pairs present in array such that i<j && A[i]>A[j];
 *
 * {5,3,2,1,4}  =>  7
 * Pairs: [(5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1)]
 *
 * Brute force: T(n^2) S(1)
 * Traverse the array and for each element count the larger elements after it
 *
 * Optimized Approch: T(nlogn) S(n)
 * Its possible to find such pairs in 2 sorted arrays easily by 2 pointer approch
 * P1 on 1st index of Array One and P2 on 1st index of Array Two.
 * then keep finding pairs such as "Arr1[P1] > Arr2[p2]" it means all the element
 * in array 1 after P1 ar also grater then Arr2[P2] so add them all in count
 * and then move the P2 forward. Other wise move the P1 forward.
 *
 * We have to inject this approch in merge sort and this will work (check the code)
 */

class Solution
{
public:
    long long modifiedMerge(vector<long long> &arr, long long s, long long m, long long e)
    {
        vector<long long> nv;
        long long i = s, j = m + 1, count = 0;
        while (i <= m && j <= e)
        {
            if (arr[i] > arr[j])
            {
                nv.push_back(arr[j]);
                count += m - i + 1;
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

    long long mergeSort(vector<long long> &arr, long long s, long long e)
    {
        if (s >= e)
        {
            return 0;
        }
        long long mid = (e + s) / 2, count = 0;
        count += mergeSort(arr, s, mid);
        count += mergeSort(arr, mid + 1, e);
        count += modifiedMerge(arr, s, mid, e);
        return count;
    }

    long long int inversionCount(vector<long long> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<long long> arr = {2, 4, 1, 3, 5}; // Example input

    cout << "Original array: ";
    for (long long val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    long long result = sol.inversionCount(arr);

    cout << "Number of inversions: " << result << endl;

    return 0;
}