#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int piviot = v[start], i = start + 1, j = end;
    while (j >= i)
    {
        if (v[i] <= piviot)
        {
            i++;
            continue;
        }
        if (v[j] >= piviot)
        {
            j--;
            continue;
        }
        if (i < j)
            swap(v[j], v[i]);
    }
    if (piviot > v[j])
        swap(v[start], v[j]);
    quickSort(v, start, j - 1);
    quickSort(v, j + 1, end);
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
    quickSort(v, 0, v.size() - 1);
    printVector(v);
    return 0;
}