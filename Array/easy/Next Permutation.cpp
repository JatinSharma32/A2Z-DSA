#include <iostream>
#include <vector>
#include <algorithm> // For sort and swap functions
using namespace std;

/**
 * Find the next permutation of an array
 * All permutations of {1,2,3} are
 *      {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}
 *
 * Brute Force: T(n! * n), S(1)
 * Find all the Permutations and then using linear search find next permutation.
 *
 * Optimized Approch: T(n.logn), S(1)
 * This approch is totally observation based
 *      -> {3,2,4,1} => {3,4,1,2}
 *            ^
 *      -> {1,2,4,3} => {1,3,2,4}
 *            ^
 *      -> {2,3,1,4} => {2,3,4,1}
 *              ^
 *      -> {2,3,5,4,1} => {2,4,1,3,5}
 *            ^
 *
 * Step 1: we observe that an element suppose arr[i] will only change if
 *         subarray after it is sorted perfectly in decending order.(check above)
 *
 * Step 2: So now we have the index which will change, but to what?
 *         It will change to the *JUST* greater element after it, like in
 *         last example, 3 is changed to 4 not 5 or 1. So in the
 *         forward remaining array we have to find the Mininmum element
 *         that is also grater then arr[i].
 *         Just swap them
 *
 * Step 3: Now we just have to sort the remaining elements as observation
 *
 */

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int updateIndex = -1, n = arr.size();
        for (int i = arr.size() - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
            {
                updateIndex = i - 1;
                break;
            }
        }
        if (updateIndex == -1)
        {
            sort(arr.begin(), arr.end());
            return;
        }
        int i = updateIndex + 1, minElemIndex = updateIndex + 1;
        for (; i < n; i++)
        {
            if (arr[i] < arr[minElemIndex] && arr[i] > arr[updateIndex])
            {
                minElemIndex = i;
            }
        }
        // for(int p=n-1;p>updateIndex;p--){
        //     if(arr[p]>arr[updateIndex]){
        //         minElemIndex=p;
        //         break;
        //     }
        // }
        swap(arr[updateIndex], arr[minElemIndex]);
        sort(arr.begin() + updateIndex + 1, arr.end());
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3};

    cout << "Original array: ";
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;

    sol.nextPermutation(arr);

    cout << "Next permutation: ";
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}