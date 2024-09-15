class Solution {
public:
    long long dp[100001][5];
    long long solve(int i,int j,vector<int>&a,vector<int>&b,int n)
    {
        if(i>=4)
        return 0;
        if(j>=n)
        {
            if(i<4)
            return INT_MIN;
            return 0;
        }
        if(dp[j][i]!=-1)
        return dp[j][i];
        long long op1 = INT_MIN,op2 = INT_MIN;
        op1 = (long long)a[i]*(long long)b[j]+solve(i+1,j+1,a,b,n);
        op2 = solve(i,j+1,a,b,n);
        return dp[j][i] = max(op1,op2);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,a,b,b.size());
    }
};