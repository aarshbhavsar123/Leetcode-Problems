class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int o = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            o|=nums[i];
        }
        int x = 1<<n;
        int count = 0;
        for(int i = 0;i<x;i++)
        {
            int sum = 0;
            for(int j = 0;j<n;j++)
            {
                if((1<<j)&i)
                {
                    sum=(sum|(nums[j]));
                }
            }
            if(sum==o)
            {
                count++;
            }
        }
        return count;
    }
};