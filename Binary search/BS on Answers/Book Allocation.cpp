#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <numeric>   // For accumulate
#include <climits>   // For INT_MAX
using namespace std;

/**
 * Description read from:
 * https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
 *
 * Brute force: T( n * ( sumOfArray - maxOfArray )), S(1)
 * We have the range (Max of Array to Sum of Array) between which our answer will lie
 * so we'll apply linear search on this range to check for how low the max page limit for
 * each student could go, the lowest will be our answer
 *
 * We'll use NoOfStudents function to find how many students can be allocated books with
 * that max limit being there. It works as:
 * We'll keep giving a book till that student is not hitting the max page limit, if he
 * hits then stop giving him more books, and give it to next student.
 * Finally at the end of books, return how many students have books.
 *
 * Optimized Approch: T(n * log(sumOfArray - maxOfArray) ), S(1)
 * We'll just apply Binary search at the place Linear search.
 *
 *    Low Max limit----------------------|-------------------------High Max limit
 *                                      Mid
 *                      <-----                      ----->
 *                  No of Students              No of Students
 *                     Increases                   decreases
 *
 */

int NoOfStudents(vector<int> &arr, int maxPages)
{
    int stud = 1, pages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pages + arr[i] <= maxPages)
        {
            pages += arr[i];
        }
        else
        {
            stud++;
            pages = arr[i];
        }
    }
    return stud;
}

int findPages(vector<int> &arr, int n, int mP)
{
    int l = *(max_element(arr.begin(), arr.end()));
    int h = accumulate(arr.begin(), arr.end(), 0);
    int minMaxPages = INT_MAX;
    if (mP > n)
    {
        return -1;
    }
    while (l <= h)
    {
        int m = (l + h) / 2;
        int students = NoOfStudents(arr, m);
        if (students <= mP)
        {
            minMaxPages = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return minMaxPages;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90}; // Example input
    int n = arr.size();
    int mP = 2; // Example number of students

    cout << "Book pages: ";
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    int result = findPages(arr, n, mP);

    if (result != -1)
    {
        cout << "Minimum number of pages each student has to read: " << result << endl;
    }
    else
    {
        cout << "It is not possible to allocate books to students." << endl;
    }

    return 0;
}