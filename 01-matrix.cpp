class Solution {
public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));   
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));            
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first.first;
            int y = top.first.second;
            int d = top.second;
            for(int i = 0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && dist[nx][ny]>1+d)
                {
                    dist[nx][ny] = 1+d;
                    q.push({{nx,ny},1+d});
                    vis[nx][ny] = true;
                }
            }
        }
        return dist;
    }
};