class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& arr) {
        int n = arr.size();
        unordered_map<double,int>mp;

        for(int i = 0;i<n;i++)
        {
            mp[(double)arr[i][0]/(double)arr[i][1]]++;
        }
        long long count = 0;
        for(auto it:mp)
        {
            long long x = it.second;
            count+=(x*(x-1))/2;
        }
        return count;
    }
};