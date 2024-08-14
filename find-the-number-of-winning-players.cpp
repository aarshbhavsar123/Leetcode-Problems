class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>>mp;
        int x = pick.size();
        for(int i = 0;i<x;i++)
        {
            mp[pick[i][0]].push_back(pick[i][1]);
        }
        int count = 0;
        for(auto it:mp)
        {
            vector<int>v = it.second;
            int i = it.first;
            unordered_map<int,int>mp2;
            for(auto jt:v)
            {
                mp2[jt]++;
            }
            bool fl = false;
            for(auto jt:mp2)
            {
                if(jt.second>i)
                {
                    fl = true;
                    break;
                }
            }
            if(fl)
            count++;
        }
        return count;
    }
};