class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(auto it:nums)
        {
            maxi = max(maxi,it);
        }
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        int ans = 0;
        for(int i = 0;i<mp[maxi].size()-1;i++)
        {
            if(mp[maxi][i]+1==mp[maxi][i+1])
            {
                count++;
                ans = max(ans,count);
            }
            else
            {
                count = 0;
            }
        }
        return ans+1;
    }
};