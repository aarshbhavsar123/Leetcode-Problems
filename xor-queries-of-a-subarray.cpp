class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prefXor(n+1,0);
        prefXor[0] = 0;
        
        for(int i = 0;i<n;i++)
        {
            prefXor[i+1] = prefXor[i]^arr[i];
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i = 0;i<q;i++)
        {
            int l = queries[i][0];

            int r = queries[i][1];
            ans[i] = prefXor[r+1]^prefXor[l];
        }
        return ans;
    }
};