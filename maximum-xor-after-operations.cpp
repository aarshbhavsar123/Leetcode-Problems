class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int r = 0;
        for(auto it:nums)
        r|=it;
        return r;
    }
};