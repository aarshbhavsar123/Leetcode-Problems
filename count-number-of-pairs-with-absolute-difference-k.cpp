class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums)
            m[i]++;  
        int count=0;
        for(int i:nums){
            if(m.find(abs(i-k))!=m.end())
                count+=m[i-k];  
            if(m.find(i+k)!=m.end())
                count+=m[i+k];  
        }
    return count/2;
    }
};