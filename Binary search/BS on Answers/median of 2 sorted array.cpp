#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

/**
 * Read Problem statement from
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * CHeck this video fro understanding the solution and DRY RUN
 * https://youtu.be/LPFhl65R7ww?si=MmxWLSMt2bXDoSit
 *
 * Brute force:
 * Make Global array or USing 2 pointers to find median.
 *
 * Optimized Solution: T(log(min(m,n))), S(1)
 * using Binary searh on answers we can find this solution.
 *
 * We know that median of global array, divides it into 2 equal parts
 *
 *       ------------------------- | ---------------------------
 *                               Median
 *
 * We also know in the right half there will be some elements from array1 and
 * some from the array2. They both are sorted so we can use this propery to divide
 * them into 4 parts
 *
 *  Array 1 => -----Part1------- | ----Part3----
 *                               ^ Partition of Array 1
 *
 *  Array 2 => ---Part2---- | -------------Part4-------------
 *                          ^ Partition of Array 2
 *
 * It means that No of elements in...
 * (also they will be equal to half of the length of the global array (n1+n2)/2)
 *          => Part1 + Part2 = Part3 + Part4 = (n1+n2)/2
 * so we can find the any Part using this above equation or vice versa right?
 *
 * Now the approch is derived using above observations, we'll find the VALID
 * Partition points in Array 1 and 2, how?
 *
 * we'll take 4 variables: x1 = (Previous point of array1's Partition)
 *                       : x2 = (array1's Partition Point)
 *                       : y1 = (Previous point of array2's Partition Point)
 *                       : y2 = (array2's Partition Point)
 *
 * now to find that if Partition points of array1 and array 2are VALID we have
 * can use a function just like (BS on answers).
 *
 * Now we have to assume Partition points on array and then find if its VALID,
 * Linearly traversing each element in array and assuming it Partition Point
 * will be time taking...
 * So to assume a point to be Partition point we'll use Binary search.
 *      => Find the smallest array
 *      => Then apply the Binary searh on it, mean suppose the Mid is the partition point
 *      => Then using this Assumption calculate the
 *                  -> x1, x2 using the Partition points an array
 *                  -> then find Partition points of other array
 *                  -> then using it find y1, y2
 * --------------------------------------------------------------------------------------
 *          (Here to handle EDGE CASE of Partition points going out of array end)
 *          (We'll assume that starting/ending of both array have -infinity/infinity)
 * --------------------------------------------------------------------------------------
 * Now using the Validiy Check Function check if the Partition is VALID
 *      => if its VALID then account of being odd or even calculate the Median
 *      => if its not VALID not then find which part to eliminate and then continue
 *      => Binary searh in that reduced search space
 *
 *
 * Check comments below in code for better understanding.
 */

class Solution
{
public:
    int eliminate(int x1, int x2, int y1, int y2)
    {
        if ((x1 <= y2) && (y1 <= x2))
        {
            // this is the perfect partition
            return 0;
        }
        else if ((x1 >= y2))
        {
            // check in the left part of arr1
            // eliminate right
            return -1;
        }

        // check in the right part of arr1
        // eliminate left
        return 1;
    }

    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();
        int halfSize = (n1 + n2 + 1) / 2; // this will change to k
        // We always assume Array 1 is smaller
        if (n1 > n2)
        {
            // if array 2 is smaller than array 1 then interchange them
            return findMedianSortedArrays(arr2, arr1);
        }

        // Now apply Binary search on smaller array to find the exact partition
        // location;
        int l = 0, h = n1;
        double ans = 0;
        while (l <= h)
        {
            int m = (l + h) / 2;
            int PX = m;
            int PY = halfSize - PX;
            // here we'll also handle the edge case, if in the left side there
            // are no elements, then we put INT_MIN in x1;
            int x1 = (PX <= 0) ? INT_MIN : arr1[PX - 1];
            int x2 = (PX >= n1) ? INT_MAX : arr1[PX];
            // here we'll also handle the edge case, if in the right side there
            // are no elements, then we put INT_MAX in y2;
            int y1 = (PY <= 0) ? INT_MIN : arr2[PY - 1];
            int y2 = (PY >= n2) ? INT_MAX : arr2[PY];

            // now elimination part come by checking if the partition is valid
            int res = eliminate(x1, x2, y1, y2);
            if (res == 0)
            {
                // calculate the median here
                if ((n1 + n2) % 2 == 0)
                {
                    // even

                    // find the last element of 1st partition
                    int mx = max(x1, y1);
                    // find the first element of 2nd partition
                    int mn = min(x2, y2);
                    ans = (double)(mx + mn) / 2;
                    break;
                }
                else
                {
                    // odd
                    int mx = max(x1, y1);
                    ans = mx;
                    break;
                }
            }
            else if (res == -1)
            {
                // eliminate right
                h = m - 1;
            }
            else
            {
                // eliminate left
                l = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {1, 3}; // Example input for first array
    vector<int> arr2 = {2};    // Example input for second array

    cout << "Array 1: ";
    for (int val : arr1)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int val : arr2)
    {
        cout << val << " ";
    }
    cout << endl;

    double result = sol.findMedianSortedArrays(arr1, arr2);

    cout << "The median of the two sorted arrays is: " << result << endl;

    return 0;
}