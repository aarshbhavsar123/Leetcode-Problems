class Solution {
public:
    int f(int x)
    {
        int sum = 0;
        while(x)
        {
            int dig = x%10;
            sum+=dig;
            x/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<n;i++)
        {
            int x = f(nums[i]);
            mp[x].push_back(nums[i]);
        }
        int maxi = -1;
        for(auto it:mp)
        {
            
            if(it.second.size()>=2)
            {
                maxi = max(maxi,it.second.back()+it.second[it.second.size()-2]);
            }
        }
        return maxi;
    }
};