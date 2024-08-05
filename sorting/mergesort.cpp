#include <bits/stdc++.h>
using namespace std;

void mergeVector(vector<int> &v, int start, int mid, int end)
{
    vector<int> newVector;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (v[i] < v[j])
        {
            newVector.push_back(v[i]);
            i++;
        }
        else
        {
            newVector.push_back(v[j]);
            j++;
        }
    }

    // Remaining elements
    while (i <= mid)
    {
        newVector.push_back(v[i]);
        i++;
    }
    while (j <= end)
    {
        newVector.push_back(v[j]);
        j++;
    }

    // copy in original vector
    for (auto &p : newVector)
    {
        v[start] = p;
        start++;
    }
}

void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    mergeVector(v, start, mid, end);
}

void printVector(vector<int> &v)
{
    cout << "Vector: ";
    for (auto &i : v)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    printVector(v);
    mergeSort(v, 0, v.size() - 1);
    printVector(v);
    return 0;
}