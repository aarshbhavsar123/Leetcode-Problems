class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>v;
        int n = nums.size();
        int count = 1;
        v.push_back(1);
        for(int i = 1;i<n;i++)
        {
            if(nums[i]==1+nums[i-1])
            {
                count++;
                v.push_back(count);
            }
            else
            {
                count = 1;
                v.push_back(count);
            }
        }
        int len = n-k+1;
        vector<int>ans;
        for(int i = 0;i<len;i++)
        {
            if(v[i+k-1]>=k)
            {
                ans.push_back(nums[i+k-1]);
            }
            else
            ans.push_back(-1);
        }

        return ans;
    }
};