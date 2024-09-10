#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * For docs use LongestSubArrayWithSumK.pdf
 */

class OptimizedSolution
{
public:
    int longestSubarrayWithSumK(vector<int> arr, long long k)
    {
        int i = 0, j = 0, maxlen = 0, n = arr.size();
        long long sum = arr[0];
        while (j < n)
        {
            if (sum == k)
            {
                maxlen = max(maxlen, j - (i - 1));
                j++;
                sum += arr[j];
            }
            else if (sum > k)
            {
                sum -= arr[i++];
                if (i > j)
                {
                    j++;
                    sum += arr[j];
                }
            }
            else
            {
                j++;
                sum += arr[j];
            }
        }
        return maxlen;
    }
};
class BetterSolution
{
public:
    int longestSubarrayWithSumK(int A[], int N, int K)
    {
        int maxLen = 0, currSum = 0;
        unordered_map<int, int> prefixSum;

        for (int i = 0; i < N; i++)
        {
            currSum += A[i];
            if (currSum == K)
            {
                maxLen = max(maxLen, i + 1);
            }
            auto ps = prefixSum.find(currSum - K);
            if (ps != prefixSum.end())
            {
                maxLen = max(maxLen, i - (ps->second));
            }
            if (prefixSum.find(currSum) == prefixSum.end())
            {
                prefixSum[currSum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    OptimizedSolution sol1;
    BetterSolution sol2;
    int A[] = {10, 5, 2, 7, 1, 9};
    vector<int> V = {10, 5, 2, 7, 1, 9};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 15;

    int result1 = sol1.longestSubarrayWithSumK(V, K);
    int result2 = sol2.longestSubarrayWithSumK(A, N, K);
    cout << "Length of the longest subarray with sum (Optimized): " << K << " is: " << result1 << endl;
    cout << "Length of the longest subarray with sum: " << K << " is: " << result2 << endl;

    return 0;
}