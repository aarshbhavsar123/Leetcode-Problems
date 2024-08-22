class Solution {
public:
    int dp[1001][1001];
    bool solve(int i,int j,string &s)
    {
        if(i>=j)
        return true;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==s[j])
        {
            return dp[i][j] = solve(i+1,j-1,s);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        for(int i = 0;i<1001;i++)
        {
            for(int j = 0;j<1001;j++)
            {
                dp[i][j] = -1;
            }
        }
        int maxLen = INT_MIN;
        int sI = 0;
        int n = s.length();
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                if(solve(i,j,s))
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen = j-i+1;
                        sI = i;
                    }
                }
            }
        }
        return s.substr(sI,maxLen);
    }
};