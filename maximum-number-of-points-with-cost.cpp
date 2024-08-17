class Solution {
public:
    long long max(long long a,long long b)
    {
        return a>b?a:b;
    }
    long long maxPoints(vector<vector<int>>& points) {
        long long n = points.size();
        long long m = points[0].size();

        vector<long long>prev(m);
        for(long long i = 0;i<m;i++)
        {
            prev[i] = points[0][i];
        }
        for(long long i = 1;i<n;i++)
        {
            vector<long long>temp = prev;
            long lMax = 0;
            for(long j = 0;j<m;j++)
            {
                long x = max(lMax-1,temp[j]);
                long res = points[i][j]+x;
                lMax = x;
                temp[j] = res;
            }
            long long rMax = 0;
            for(long long j = m-1;j>=0;j--)
            {
                long long x = max(rMax-1,prev[j]);
                long long res = points[i][j]+x;
                rMax = x;
                prev[j] = max(res,temp[j]);
            }
        }
        long long maxi = INT_MIN;
        for(auto it:prev)
        {
            maxi = max(maxi,it);
        }
        return maxi;
    }
};