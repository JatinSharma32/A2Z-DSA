#include <iostream>
#include <vector>
using namespace std;

/**
 * Make Pascal triangle till n rows
 *       1
 *      1 1
 *     1 2 1
 *    1 3 3 1
 *   1 4 6 4 1
 *  1 5 10 10 5 1
 * 1 6 15 20 15 6 1
 *
 * Optimized Solution 1: T(n^2), S(1)
 * We will actually use the concept of pascal triangle, {that its sum of previous rows
 * 2 elements}, Make a nested vector.
 * We will run a loop n times, on each iteration we will make array of size i+1 with 1s
 * then traverse it from 1 index till i-1 as 0 and i index's value will always be 1.
 * So on each inner loops iteration we'll put previous row's j and j-1's sum.
 *
 *                                  OR
 * Using Mathematical Observation https://www.youtube.com/watch?v=bR7mQgwQ_o8
 * elements at i,j index in pascal triangle is
 *     (i-1)
 *          C
 *           (j-1)
 */

class Solution
{
public:
    vector<vector<int>> generateOptimized(int n)
    {
        vector<vector<int>> tri;
        for (int i = 0; i < n; i++)
        {
            vector<int> row = {1};
            int faq = 1;
            for (int j = 1; j <= i; j++)
            {
                faq = faq * ((i + 1) - j) / j;
                row.push_back(faq);
            }
            tri.push_back(row);
        }
        return tri;
    }
    vector<vector<int>> generate(int num)
    {
        vector<vector<int>> triangle;
        for (int i = 0; i < num; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main()
{
    Solution sol;
    int n = 5; // Number of rows in Pascal's Triangle

    vector<vector<int>> result = sol.generateOptimized(n);

    cout << "Pascal's Triangle with " << n << " rows:" << endl;
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}