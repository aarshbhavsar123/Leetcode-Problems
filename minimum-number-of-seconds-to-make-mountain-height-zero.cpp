class Solution {
public:
    bool check(long long mt, int mh, vector<int>& wt) {
    long long total = 0;
    for (long long i = 0; i < wt.size(); i++) {
            long long timeSpent = 0;
            long long j = 1;
            while (timeSpent + wt[i] * j <= mt) {
                timeSpent += wt[i] * j;
                total++;
                j++;
                if (total >= mh) return true;
            }
        }
        return total >= mh;
    }

    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long s = 0;
        long long e = 1e18;
        long long mid = s+(e-s)/2;
        long long ans = -1;
        while(s<=e)
        {
            if(check(mid,mh,wt))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};