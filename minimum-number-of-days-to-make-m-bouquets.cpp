class Solution {
public:
    bool poss(int day,int k,vector<int>&v,int m)
    {
        int count = 0;
        int n =v.size();
        int countB = 0;
        for(int i = 0;i<n;i++)
        {
            if(v[i]<=day)
            {
                count++;
                if(count==k)
                {
                    count = 0;
                    countB++;
                }
            }
            else
            {
                count = 0;
            }

        }
        return countB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0;
        int maxi  = INT_MIN;
        int n = bloomDay.size();
        for(int i = 0;i<n;i++)
        {
            maxi = max(maxi,bloomDay[i]);
        }
        int e = maxi;
        int mid = s+(e-s)/2;
        int ans = 0;
        while(s<=e)
        {
            if(poss(mid,k,bloomDay,m))
            {
                e = mid-1;
                ans = mid;
            }
            else
            {
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans==0?-1:ans;
    }
};