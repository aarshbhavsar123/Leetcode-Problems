class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>&mat,int n)
    {
        if(i>=n||j>=n||i<0||j<0)
        return INT_MAX;

        if(i==n-1)
        return mat[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int op1 = solve(i+1,j-1,mat,n);
        int op2 = solve(i+1,j,mat,n);
        int op3 = solve(i+1,j+1,mat,n);

        return dp[i][j] = min({op1,op2,op3})+mat[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mini = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++)
        {
            mini = min(mini,solve(0,i,mat,n));
        }
        return mini;
    }
};