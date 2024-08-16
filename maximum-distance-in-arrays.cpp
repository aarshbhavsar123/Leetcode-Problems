class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int ans = 0;
        int n = arrays.size();
        for(int i = 1;i<n;i++)
        {
            ans = max(ans,abs(arrays[i].back()-mini));
            ans = max(ans,abs(arrays[i][0]-maxi));
            mini = min(mini,arrays[i][0]);
            maxi = max(maxi,arrays[i].back());
            
        }
        return ans;
    }
};