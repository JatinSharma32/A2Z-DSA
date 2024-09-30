#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

/**
 * Find elements which appears more then (n/3) times in list
 * {1,2,2,3,2} => 2
 * {11,33,33,11,33,11}=> 11, 33
 *
 * Brute Force: T(n^2) S(1)
 * Count every element's frequency and return those with more then n/3 occurance.
 *
 * Better Way: T(n) S(n)
 * Use hash map to count occurance and return those with more then n/3 occurance.
 *
 * Best Way: T(n) S(n)
 * Moore's voting algorithm can be used here
 * Just convert solution for Majority Element 1 (where we had to find element
 * with more then n/2 occurance) to 2 elements solution
 * The concept is exactly same.
 */

class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int elem1 = INT_MIN, count1 = 0, elem2 = INT_MIN, count2 = 0;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (count1 == 0 && arr[i] != elem2)
            {
                elem1 = arr[i];
                count1++;
            }
            else if (count2 == 0 && arr[i] != elem1)
            {
                elem2 = arr[i];
                count2++;
            }
            else if (arr[i] == elem1)
            {
                count1++;
            }
            else if (arr[i] == elem2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == elem1)
            {
                count1++;
            }
            else if (arr[i] == elem2)
            {
                count2++;
            }
        }
        if (count1 > arr.size() / 3)
        {
            ans.push_back(elem1);
        }
        if (count2 > arr.size() / 3)
        {
            ans.push_back(elem2);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 3, 1, 2, 1, 1, 2, 2};

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result = sol.majorityElement(arr);

    cout << "Majority elements (appearing more than n/3 times): ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}