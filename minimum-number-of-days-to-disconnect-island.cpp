class Solution {
public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid,int n,int m)
    {
        vis[i][j] = true;
        for(int k = 0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
            {
                dfs(nx,ny,vis,grid,n,m);
            }
        }
    }
    int func(vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    dfs(i,j,vis,grid,n,m);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int x = func(grid);
        cout<<x<<endl;
        if(x!=1)
        {
            return 0;
        }
        else
        {
            int n = grid.size();
            int m = grid[0].size();
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j]=0;
                        if(func(grid)!=1)
                        {
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
            return 2;
        }
    }
};
