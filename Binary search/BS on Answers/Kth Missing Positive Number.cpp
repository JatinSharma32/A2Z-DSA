#include <iostream>
#include <vector>
using namespace std;

/**
 * using binary search
 * We'll have to figure out the 2 numbers between which the missing number
 * is present How? we can easily find how many numbers are missing till now
 * using
 *
 * missing numbers till now = number in array (arr[i]) - actaully which integer
 * should have been here (i+1)
 *
 * Now on this we can apply Binary search to find the lower bound of k say
 * it 'j' and a previous index 'i' so, basically the kth missing number
 * will lie between 'i' and 'j' index.
 */

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k < arr[0])
        {
            return k;
        }
        // using binary search
        int l = 0, h = n - 1;
        int LB = n;
        while (l <= h)
        {
            int m = (l + h) / 2;
            int mTN = arr[m] - (m + 1);
            if (mTN >= k)
            {
                LB = m;
                h = m - 1;
            }
            else if (mTN < k)
            {
                l = m + 1;
            }
        }
        // now we know missing is between 'i' and 'j'
        int i = LB - 1, j = LB;
        if (i <= -1)
        {
            return k;
        }
        else
        {
            return arr[i] + (k - (arr[i] - (i + 1)));
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11}; // Example input
    int k = 5;                          // Example k

    cout << "Array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = sol.findKthPositive(arr, k);

    cout << "The " << k << "th missing positive number is: " << result << endl;

    return 0;
}