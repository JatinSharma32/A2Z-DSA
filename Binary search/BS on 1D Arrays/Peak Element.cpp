#include <iostream>
#include <vector>
using namespace std;

/**
 * Find the Peak Element in the array, its an element that is greater then
 * both of its adjecent elements, at the both ends of array its negative infinity
 * Return the index of any Peak element if multiple.
 * [1,2,1,3,5,6,4] => 5
 *            ^
 *
 * Brute Force: T(n), S(1)
 * Using Linear search we traverse the array and search for element under condition
 *
 * Optimize Solution: T(logn), S(1)      Using Binary Search
 * In this question peak element depends on 2 adjecent elements so we have to check
 * them both everytime, here for first (no previous element) and last(no next element)
 * there will be edge cases, so we have to check manually if 1st and last elements
 * are peak.
 *
 * Now for the remaining array [1 to n-2] we can use binary search approch of half
 * elimination to reduce Time complexity to O(logn),
 *  => So there will be 3 cases if mid is on peak element check then return index
 *
 *  => else if (prev < mid < next) then we have to eliminate all the smaller
 *     elements in the left half.
 *
 *  => else (prev > mid > next) then we have to eliminate all the smaller
 *     elements in the right half.
 *
 */

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        // Edge cases
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }
        // if first element is peak
        if (arr[0] > arr[1])
        {
            return 0;
        }

        // if last element is peak
        if (arr[n - 1] > arr[n - 2])
        {
            return n - 1;
        }

        // Normal cases
        int l = 1, h = n - 2;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            // check if current element is peak
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            // check in which curve we are

            // check for Increasing curve
            else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
            {
                // So remove the left half which have smaller elements
                l = mid + 1;
            }
            // check for Decreasing curve
            else
            {
                // So remove the right half which have smaller elements
                h = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 1}; // Example input

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.findPeakElement(arr);

    if (result != -1)
    {
        cout << "Peak element found at index: " << result << endl;
    }
    else
    {
        cout << "No peak element found." << endl;
    }

    return 0;
}