class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_set<int> st = {60, 120, 180, 240, 300, 360, 420, 480,540,600,660,720,780,840,900,960,1020};
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i < time.size(); i++)
        {
            for(auto it: st)
            {
                if(mp.find(it - time[i]) != mp.end())
                {
                    count += mp[it - time[i]];
                }
            }
            mp[time[i]]++;
        }
        return count;

    }
};
