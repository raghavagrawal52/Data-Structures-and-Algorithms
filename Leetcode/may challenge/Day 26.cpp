// This problem can be solved using DP and concept of prefix sum
// have a count and if number is 0 subtract 1 else increment 1
// then find length in the map where key -1 and 0 that will give the length
// have a max_len and keep storing the max value of the length in max_len

class Solution
{
public:
    int max_len = 0;
    unordered_map<int, int> dp;
    int count = 0;

    int findMaxLength(vector<int> &nums)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        dp[0] = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
                count++;
            else
                count--;
            // You can also use ternary operator to update count and shorten the syntax
            
            if (!dp.count(count))
                dp[count] = i;
            max_len = max(max_len, i - dp[count]);
        }
        return max_len;
    }
};
