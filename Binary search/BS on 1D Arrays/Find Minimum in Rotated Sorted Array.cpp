/**
 * A sorted array is rotated on a piviot, we have to find 'x' in it and return
 * its smallest element.
 * [4,5,6,7,0,1,2] => 0
 *
 * Brute force: T(n) S(1)
 * Using linear search
 *
 * Optimized Approch: T(logn) S(1)
 * In binary search we will check if the midd element is grater then both low and
 * high it means smallest element is in right part
 * as left part is sorted so eliminate it, l=m;
 *
 * If the mid element is smaller then both low and high it means possibly it can
 * be smallest element so keep it in the search space and eliminate the right part
 * as all the elements between mid and hight will be grater then mid, so h=m;
 *
 * And check in starting if there are only 2 elements in search space and the
 * high is smaller then low then return high. it will always happen.
 *
 * Edge case: If array is sorted, check 0th and n-1th index if a[0]<=a[n-1] then
 * return arr[0];
 */

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0, h = n - 1;
        int index = 0;
        if (arr[l] < arr[h] || n == 1)
        {
            return arr[index];
        }
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (l + 1 == h && arr[l] > arr[h])
            {
                return arr[h];
            }
            else if (arr[l] < arr[m] && arr[h] < arr[m])
                l = m;
            else if (arr[l] > arr[m] && arr[h] > arr[m])
                h = m;
        }
        return arr[index];
    }
};