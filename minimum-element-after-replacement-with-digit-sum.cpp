class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            int x = 0;
            int y = nums[i];
            while(y)
            {
                x+=y%10;
                y/=10;
            }
            mini = min(mini,x);
        }
        return mini;
    }
};