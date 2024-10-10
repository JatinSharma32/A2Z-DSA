#include <bits/stdc++.h>
using namespace std;

// Using Mathematics
vector<int> findMissingRepeatingNumbers(vector<int> arr)
{
    long long n = arr.size();
    long long sumArr = 0, sumN = n * (n + 1) / 2;
    long long sumSqrArr = 0, sumSqrN = n * (n + 1) * (2 * n + 1) / 6;

    for (int i = 0; i < n; i++)
    {
        sumArr += arr[i];
        sumSqrArr += (long long)arr[i] * (long long)arr[i];
    }

    long long eq1 = sumArr - sumN;
    long long eq2 = (sumSqrArr - sumSqrN) / eq1;

    long long twice = (eq1 + eq2) / 2;
    long long missing = (eq2 - twice);

    return {(int)twice, (int)missing};
}

// USING SORTING
vector<int> findMissingRepeatingNumbersUsingSorting(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int missing, twice;
    int XOR = arr[0], XORNN = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
        XORNN = XORNN ^ (i + 1);
        int diff = arr[i] - arr[i - 1];
        if (diff == 0)
        {
            twice = arr[i];
        }
    }
    missing = XOR ^ XORNN ^ twice;
    return {twice, missing};
}

int main()
{
    vector<int> arr = {1, 2, 2, 4}; // Example input

    cout << "Original array: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result = findMissingRepeatingNumbers(arr);

    cout << "Twice appearing number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}