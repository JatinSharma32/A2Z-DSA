#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Find all the possible sub arrays with XOR k
 * [4, 2, 2, 6, 4] , k = 6
 * => No of subarrays 4 => [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
 *
 * Optimized: T(n) S(n)
 * We will maintain a prefix XOR of array in "unordered_map", and then traverse
 * the array on each iteration
 *  => update XOR itself and to map by updating its no of times Occurance
 *     "XORMap[XOR]++".
 *  => if XOR is k then increase count;
 *  => then find how many more sub arrays with XOR K are there by removing previous
 *     subarrays. add them to count "count += XORMap[XOR ^ b]".
 * Return count finally.
 *
 */

int subarraysWithSumK(vector<int> arr, int b)
{
    int XOR = 0, count = 0;
    unordered_map<int, int> XORMap;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
        if (XOR == b)
        {
            count++;
        }
        if (XORMap.find(XOR ^ b) != XORMap.end())
        {
            count += XORMap[XOR ^ b];
        }
        XORMap[XOR]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = subarraysWithSumK(arr, k);
    cout << "Number of subarrays with XOR sum " << k << ": " << result << endl;

    return 0;
}