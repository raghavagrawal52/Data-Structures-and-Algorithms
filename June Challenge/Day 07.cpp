// This is a DP problem
// similar to the 0/1 knapsack problem

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount+1][n+1];
        
        for(int i=0;i<n+1;++i)
            dp[0][i] = 1;
        for(int i=1;i<amount+1;++i)
            dp[i][0] = 0;
        
        for(int i=1;i<amount+1;++i)
            for(int j=1;j<n+1;++j){
                if(i < coins[j-1])
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j];
            }
        
        return dp[amount][n];
    }
};
