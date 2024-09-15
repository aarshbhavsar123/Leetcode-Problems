class TrieNode{
    public:
    vector<TrieNode*>children;
    TrieNode()
    {
        vector<TrieNode*>v(26,NULL);
        this->children = v;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode();
    }
    void insert(string w)
    {
        TrieNode* temp = root;
        for(auto it:w)
        {
            int i = it-'a';
            if(temp->children[i]==NULL)
            {
                temp->children[i] = new TrieNode();
            }
            temp = temp->children[i];
        }
    }
};
class Solution {
public:
    long long dp[5001];
    long long min(long long x,int y)
    {
        return x<y?x:y;
    }
    long long solve(int i,TrieNode* root,string target,int n)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        TrieNode* temp = root;
        long long mini = INT_MAX;
        for(int j = i;j<n;j++)
        {
            int idx = target[j]-'a';
            if(temp->children[idx]==NULL)
            break;
            temp = temp->children[idx];
            int t = solve(j+1,root,target,n);
            if(t!=INT_MAX)
            {
                mini = min(mini,1+t);
            }
        }
        return dp[i] = mini;
    }
    int minValidStrings(vector<string>& words, string target) {
        Trie* t = new Trie();
        for(auto it:words)
        {
            t->insert(it);
        }
        int n = target.length();
        memset(dp,-1,sizeof(dp));
        int x = solve(0,t->root,target,n);
        
        return x==INT_MAX?-1:x;
    }
};