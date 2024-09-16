class Solution {
public:
    int solve(string s)
    {
        string s1,s2;
        s1.push_back(s[0]);
        s1.push_back(s[1]);
        int x1 = stoi(s1);
        s2.push_back(s[3]);
        s2.push_back(s[4]);
        int x2 = stoi(s2);
        if(x1==0 && x2==0)
        {
            return 24*60;
        }
        else
        {
            return x1*60+x2;
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>minutes(n);
        for(int i = 0;i<n;i++)
        {
            int x = solve(timePoints[i]);
            minutes[i] = x;
        }
        sort(minutes.begin(),minutes.end());
        int mini = INT_MAX;
        for(int i = 0;i<n-1;i++)
        {
            mini = min(mini,(minutes[i+1]-minutes[i])%1440);
        }
        return min(mini,24*60-minutes[n-1]+minutes[0]);
    }
};
