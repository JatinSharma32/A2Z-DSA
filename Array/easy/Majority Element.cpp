#include <iostream>
#include <vector>
using namespace std;

/**
 * Find an element that occurs more then n/2 times.
 *
 * Brute Force: T(n^2), S(1)
 * count each element in array.
 *
 * Better approch: T(n), S(n)
 * Unordered map to sore the Frequency of each element,
 * while storing check who's freq goes beyond n/2
 *
 * Optimized Solution: T(2n), S(1)
 *              Moore's Voting Algo
 * Here we take 2 varibles count=0 and element=null
 * count will keep the Frequency of element.
 *      -> If count=0 put the Current element in element
 *      -> Else if Current element is element then increase count
 *      -> Else if Current element is not element then decrease count
 * Finally out of verify element's freq is more then n/2
 *
 * Basically we assume that the 1st element is occuring n/2
 * so we keep increasing count for same element further and decreasing it
 * for different element if count becomes zero it means that element is
 * present less then i/2 times till now, thats why it perfectly
 * canceled out in terms of freq with different elements.
 */

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int count = 0, elem, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                elem = arr[i];
                count++;
                continue;
            }
            if (elem == arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int countElem = 0;
        for (auto i : arr)
        {
            if (i == elem)
            {
                countElem++;
            }
        }
        if (countElem > n / 2)
        {
            return elem;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(arr);
    if (result != 0)
    {
        cout << "The majority element is: " << result << endl;
    }
    else
    {
        cout << "There is no majority element." << endl;
    }

    return 0;
}