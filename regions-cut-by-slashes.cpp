class Solution {
public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&ans,vector<vector<bool>>&vis,int n)
    {
        vis[i][j] = true;
        for(int k = 0;k<4;k++)
        {
            int newx = i+dx[k];
            int newy = j+dy[k];
            if(newx>=0 && newx<n && newy>=0 && newy<n && !vis[newx][newy] && ans[newx][newy]==0)
            {
                dfs(newx,newy,ans,vis,n);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(3*n,vector<int>(3*n,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int starti = 3*i;
                    int startj = 3*j;
                    for(int row = 0;row<3;row++)
                    {
                        ans[row+starti][2-row+startj] = 1;
                    }
                    
                }
                else if(grid[i][j]=='\\')
                {
                    int starti = 3*i;
                    int startj = 3*j;
                    for(int row = 0;row<3;row++)
                    {
                        ans[row+starti][row+startj] = 1;
                    }
                }
            }
        }
        n = ans.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(ans[i][j]==0 && !vis[i][j])
                {
                    dfs(i,j,ans,vis,n);
                    count++;
                }
            }
        }
        return count;
    }
};