class Solution {
public:
    const long long mod = 1e9+7;
    long long dp[51][51][51];
    long long solve(int i,int j,int n,int m,int maxMoves)
    {
        
        
        if((i<0||i>=n||j<0||j>=m))
        {
            return 1;
        }
        if(maxMoves<=0)
        return 0;
        
        if(dp[i][j][maxMoves]!=-1)
        return dp[i][j][maxMoves];
        int op1 = 0,op2 = 0,op3 = 0,op4 = 0;
        op1 = solve(i+1,j,n,m,maxMoves-1);
        op2 = solve(i,j+1,n,m,maxMoves-1);
        op3 = solve(i-1,j,n,m,maxMoves-1);
        op4 = solve(i,j-1,n,m,maxMoves-1);
        return dp[i][j][maxMoves] = (op1%mod+op2%mod+op3%mod+op4%mod)%mod;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,n,m,maxMove);
    }
};