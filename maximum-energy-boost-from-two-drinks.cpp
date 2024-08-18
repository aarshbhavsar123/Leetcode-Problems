class Solution {
public:
    long long dp[100001][3];
    long long solve(int i,int n,vector<int>&A,vector<int>&B,bool x)
    {
        if(i>=n)
        return 0;

        if(dp[i][x]!=-1)
        return dp[i][x];
        long long op1 = INT_MIN;
        if(x==0)
        {
            op1 = max(A[i]+solve(i+1,n,A,B,0),solve(i+1,n,A,B,1));
        }
        else {
            op1 = max(B[i]+solve(i+1,n,A,B,1),solve(i+1,n,A,B,0));
        }
        return dp[i][x] = op1;
    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        memset(dp,-1,sizeof(dp));
        return max(solve(0,A.size(),A,B,0),solve(0,A.size(),A,B,1));
    }
};
