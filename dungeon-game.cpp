class Solution {
public:
    int dp[201][201];
    long long solve(int i,int j,int n,int m, vector<vector<int>>&grid)
    {
        if(i==n-1 && j==m-1)
        {
            if(grid[i][j]>0)
            return 0;
            return grid[i][j];
        }

        if(i<0||i>=n||j<0||j>=m)
        return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long op1 = grid[i][j]+solve(i+1,j,n,m,grid);
        long long op2 = grid[i][j]+solve(i,j+1,n,m,grid);
        return dp[i][j] = max(op1,op2)>0?0:max(op1,op2);
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        long long x = solve(0,0,n,m,grid);
        return x>0?1:-1*x+1;
    }
};
