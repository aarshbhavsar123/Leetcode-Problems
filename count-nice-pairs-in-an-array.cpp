class Solution {
public:
    const int mod = 1e9+7;
    int rev(int x)
    {
        int ans = 0;
        int y = x;
        vector<int>v;
        while(y)
        {
            int digit = y%10;
            v.push_back(digit);
            y/=10;
        }
        int z = v.size();
        
        for(int i = 0;i<z;i++)
        {
            ans+=pow(10,z-i-1)*v[i];
        }

        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(auto it:nums)
        {
            mp[it-rev(it)]++;
        }
        int ans = 0;
        
        for(auto it:mp)
        {
            long long x = it.second;
            x%=mod;
            long long z = (x*(x-1))/2;
            z%=mod;
            ans = (ans%mod+z)%mod;
        }
        return ans%mod;
    }
};