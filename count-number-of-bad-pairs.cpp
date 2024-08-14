class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long n = nums.size();
        for(long long i = 0;i<n;i++)
        {
            mp[i-nums[i]]++;
        }
        long long count = 0;
        for(auto it:mp)
        {
            long long x = it.second;
            count+=(x*(x-1))/2;
        }
        return (n*(n-1))/2-count;
    }
};