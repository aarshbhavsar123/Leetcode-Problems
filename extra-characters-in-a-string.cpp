class Solution {
public:
    int dp[51];
    int solve(int i,string s,unordered_set<string>&st,int n)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans = INT_MAX;
        for(int j = i;j<n;j++)
        {
            string sub = s.substr(i,j-i+1);
            if(st.find(sub)!=st.end())
            {
                ans = min(ans,solve(j+1,s,st,n));
            }
        }
        ans = min(ans,1+solve(i+1,s,st,n));
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n =s.length();
        unordered_set<string>st;
        for(auto it:dictionary)
        {
            st.insert(it);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st,n);
    }
};