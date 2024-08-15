#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int s, int n)
{
    if (s >= n)
    {
        return;
    }
    for (int i = s - 1; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
        else
        {
            break;
        }
    }
    insertionSort(arr, s + 1, n);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, 0, n);
    printArray(arr, n);
    return 0;
}
