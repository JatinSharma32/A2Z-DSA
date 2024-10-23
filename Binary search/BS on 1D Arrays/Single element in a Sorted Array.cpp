#include <iostream>
#include <vector>
using namespace std;

/**
 * Find the Single Element in the array of duplicates, its an element that is
 * appearing once only, Return the element.
 * [1,1,2,3,3,4,4,8,8] => 2
 *      ^
 *
 *
 * Brute Force: T(n), S(1)
 * Using Linear search we traverse the array and search for element under condition
 *
 * Optimize Solution: T(logn), S(1)      Using Binary Search
 * In this question the single element can be found using adjecent elements and
 * their indexing, like before the single element, same element pair's index
 * would look like (even , odd), and after single element it would be like
 * (odd, even), this was the observation.
 * So in this single element depends on 2 adjecent elements so we have to check
 * them both everytime, here for first (no previous element) and last(no next element)
 * there will be edge cases, so we have to check manually if 1st and last elements
 * are single.
 *
 * Now for the remaining array [1 to n-2] we can use binary search approch of half
 * elimination to reduce Time complexity to O(logn),
 *  => So there will be 3 cases if mid is single element check then return index.
 *
 *  => else if mid is even and its next element is same or midd is odd and
 *     its previous element is same then we know we are before the single element
 *     element, so eliminate the left half
 *
 *  => else (prev > mid > next) otherwise we are in the right half, so eliminate it.
 *
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0];
        }
        if (arr[n - 1] != arr[n - 2])
        {
            return arr[n - 1];
        }
        if (arr[0] != arr[1])
        {
            return arr[0];
        }

        int l = 1, h = n - 2, ans = 0;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if ((arr[mid] != arr[mid - 1]) && (arr[mid] != arr[mid + 1]))
            {
                ans = arr[mid];
                break;
            }
            else if (((mid % 2 == 0) && (arr[mid] == arr[mid + 1])) ||
                     ((mid % 2 == 1) && (arr[mid] == arr[mid - 1])))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // Example input

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.singleNonDuplicate(arr);

    cout << "Single non-duplicate element: " << result << endl;

    return 0;
}