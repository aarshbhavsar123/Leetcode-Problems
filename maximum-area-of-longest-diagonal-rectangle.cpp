class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = INT_MIN;
        int n = dimensions.size();
        
        for(int i = 0;i<n;i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            if(l*l+b*b>maxi)
            {
                maxi = l*l+b*b;
            }
        }
        int ans = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            if(l*l+b*b==maxi)
            {
                ans = max(ans,l*b);
            }
        }
        return ans;
    }
};