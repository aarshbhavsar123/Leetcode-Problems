class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        int val = 0;
        for(int i = 0;i<n;i++)
        {
            val+=(i)*(nums[i]);
        }
        dp[0] = val;
        int prev = nums[n-1]*(n-1);
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
        }
        for(int i = 1;i<n;i++)
        {
            dp[i] = dp[i-1]-prev+(sum-nums[n-i]);
            prev = nums[n-i-1]*(n-1);
            val = max(val,dp[i]);
        }
        return val;
    }
};