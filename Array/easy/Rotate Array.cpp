
/**
 * Rotate Array by K places
 * [1,2,3,4,5,6,7] to [5,6,7,1,2,3,4]
 *
 *          Brute force: T(n), S(n)
 * We store last k elements in temp array
 * then move all elemets from indices [0 , k] k steps forward
 * finally put the temp array elemets bact in original array from [0 , k]
 *
 *          Optimized Solution: T(n), S(1)
 * reverse 0 to k
 * reverse k to n
 * finally Reverse 0 to n
 *
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        stack<int> elem;
        int n = nums.size();
        if (k > n)
        {
            k = k % n;
        }
        for (int i = n - k; i < n; i++)
        {
            elem.push(nums[i]);
        }
        for (int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        for (int i = k - 1; i >= 0; i--)
        {
            nums[i] = elem.top();
            elem.pop();
        }
    }
};
