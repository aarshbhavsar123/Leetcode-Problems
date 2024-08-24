class Solution {
public:
    bool bipartite(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int color,vector<int>&col)
    {
        vis[node] = true;
        col[node] = color;
        bool ans = true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                ans=ans&&bipartite(it,adj,vis,!color,col);
            }
            else 
            {
                if(col[node]==col[it])
                {
                    return false;
                }
            }
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>col(n+1,-1);
        vector<bool>vis(n+1,false);
        for(int i = 1;i<=n;i++)
        {
            if(!vis[i] && !bipartite(i,adj,vis,0,col))
            {
                return false;
            }
        }
        return true;
    }
};