// This problwem can be solved using DP
// It can be a tricky problem but once understood the concept can be solved easily
// create a new 2d vector for the dp and store the max if A[i] != B[j]
// or else increment the diagonal by 1 from the current element

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (A.size() == 0 || B.size() == 0)
            return 0;
        int n1 = A.size(), n2 = B.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < n2; ++j)
            {
                // This is for incrementing diagonal
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                // This is for the max b/w the right and bottom element
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        return dp[n1][n2];
    }
};