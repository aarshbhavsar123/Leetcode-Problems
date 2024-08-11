class Solution {
public:
    int count = 0;
    int dfs(int node,int pr,unordered_map<int,vector<int>>&adj)
    {
        int tot = 1;
        unordered_set<int>st;
        for(auto it:adj[node])
        {
            if(it!=pr)
            {
                int x = dfs(it,node,adj);
                st.insert(x);
                tot+=x;
            }
        }
        if(st.size()<=1)
        count++;

        return tot;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int x = dfs(0,-1,adj);
        return count;
    }
};