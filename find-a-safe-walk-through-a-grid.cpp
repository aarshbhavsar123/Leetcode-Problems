class Solution {
public:
    int dp[51][51][101];
    bool solve(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&vis,int health)
    {
        if(i==n-1 && j==m-1)
        {
            if(health-grid[i][j]>=1)
            return true;
            return false;
        }
        if(health<0)
        return false;
        if(i>=n||i<0||j>=m||j<0||vis[i][j])
        return false;
        if(dp[i][j][health]!=-1)
        return dp[i][j][health];
        bool op1 = false,op2 = false,op3 = false,op4 = false;
        vis[i][j] = true;
        op1 = solve(i+1,j,n,m,grid,vis,health-grid[i][j]);
        op2 = solve(i-1,j,n,m,grid,vis,health-grid[i][j]);
        op3 = solve(i,j+1,n,m,grid,vis,health-grid[i][j]);
        op4 = solve(i,j-1,n,m,grid,vis,health-grid[i][j]);
        vis[i][j] = false;
        return dp[i][j][health] = op1||op2||op3||op4;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,grid,vis,health);
    }
};