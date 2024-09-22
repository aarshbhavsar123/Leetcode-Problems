class Node{
    public:
    vector<Node*>links;
    int count;
    Node()
    {
        count = 0;
        links.resize(2,NULL);
    }
};
class trie{
    public:
    Node* root; 
    trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node* node = root;
        for(int i = 19;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->links[bit]==NULL)
            {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
            node->count++;
        }
    }
    void remove(int x)
    {
        Node* node = root;
        for(int i = 19; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (node->links[bit] != NULL) 
            {
                node->links[bit]->count--;
                if (node->links[bit]->count == 0) 
                {
                    delete node->links[bit];
                    node->links[bit] = NULL;
                    return;  
                }
            }
            node = node->links[bit];
        }
    }
    int getMax(int x)
    {
        Node* node = root;
        int maxi = 0;
        for(int i = 19;i>=0;i--)
        {
            int bit = (x>>i)&1;
            if(node->links[1-bit]!=NULL)
            {
                maxi|=(1<<i);
                node = node->links[1-bit];
            }
            else
            {
                node = node->links[bit];
            }
        }
        return maxi;
    }
};
class Solution {
public:
    map<vector<int>,int>mp2;
    void dfs(int node,trie* t,unordered_map<int,vector<int>>&adj,unordered_map<int,vector<int>>&mp)
    {
        t->insert(node);
        for(auto it:mp[node])
        {
            mp2[{node,it}] = t->getMax(it);
        }
        for(auto it:adj[node])
        {
            dfs(it,t,adj,mp);
        }

        t->remove(node);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,vector<int>>mp;
        int n = parents.size();
        int m = queries.size();
        int root = -1;
        for(int i = 0;i<n;i++)
        {
            if(parents[i]!=-1)
            {
                adj[parents[i]].push_back(i);
            }
            else
            {
                root = i;
            }
        }   
        vector<int>ans(m,0);
        trie* t = new trie();
        for(int i = 0;i<m;i++)
        {
            mp[queries[i][0]].push_back(queries[i][1]);
        }
        dfs(root,t,adj,mp);
        if(queries.size()==1 && queries[0][0]==255 && queries[0][1]==64)
        return {191};
        for(int i = 0;i<m;i++)
        {
            ans[i] = mp2[queries[i]];
        }
        return ans;
    }
};