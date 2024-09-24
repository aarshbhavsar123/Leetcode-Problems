class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            dq.push_back(nums[i]);
        }
        while(k--)
        {
            int x = dq.back();
            dq.pop_back();
            dq.push_front(x);
        }
        vector<int>ans;
        while(!dq.empty())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        nums = ans;
    }
};