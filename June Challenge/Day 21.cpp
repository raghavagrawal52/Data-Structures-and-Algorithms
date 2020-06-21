class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = 1, dp[m-1][n] = 1;
        
        for(int i=m; i>0; --i)
            for(int j=n; j>0; --j){
                dp[i-1][j-1] = min(dp[i][j-1], dp[i-1][j]) - dungeon[i-1][j-1];
                if(dp[i-1][j-1] <= 0)
                    dp[i-1][j-1] = 1;
            }
        
        return dp[0][0];
    }
};
