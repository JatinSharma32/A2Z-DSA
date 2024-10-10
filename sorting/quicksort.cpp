#include <bits/stdc++.h>
using namespace std;

// int Pivot(vector<int>& arr, int s, int e){
//     int i=s+1,j=e, pivot=arr[s];
//     while(i<j){
//         while(arr[i]<=pivot && i<j) i++;
//         while(arr[j]>pivot && i<j) j--;
//         swap(arr[i],arr[j]);
//     }
//     if(arr[s]>arr[j]){
//         swap(arr[s],arr[j]);
//         return j;
//     }else{
//         swap(arr[s],arr[j-1]);
//         return j-1;
//     }
// }

// void QuickSort(vector<int>& arr, int s, int e){
//     if(s>=e){
//         return;
//     }
//     int pivot=Pivot(arr,s,e);
//     QuickSort(arr,s,pivot-1);
//     QuickSort(arr,pivot+1, e);
// }

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