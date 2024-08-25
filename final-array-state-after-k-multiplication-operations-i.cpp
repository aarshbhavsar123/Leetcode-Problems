class Solution {
public:
    const int mod = 1e9+7;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            long long val = top.first;
            pq.push({((val%mod)*(multiplier%mod))%mod,idx});
        }
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            long long val = top.first;
            nums[idx] = val;
        }
        return nums;
    }
};