class Solution {
public:
    const int mod = 1e9+7;
    int dp[2001][52][52];
    int solve(int i,int prev1,int prev2,vector<int>&nums,int n)
    {
        if(i>=n)
        return 1;

        if(dp[i][prev1][prev2]!=-1)
        return dp[i][prev1][prev2];

        int x = nums[i];
        int ans = 0;
        for(int k = prev1;k<=nums[i];k++)
        {
            int val = nums[i]-k;
            if(val<=prev2)
            {
                 ans=(ans+solve(i+1,k,val,nums,n))%mod;
            }           
        }
        return dp[i][prev1][prev2] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(0,0,51,nums,n);
    }
};