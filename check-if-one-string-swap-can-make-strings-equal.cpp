class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
        return true;
        int n = s1.length(),m = s2.length();
        if(n!=m)
        return false;
        vector<int>v;
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            v.push_back(i);
        }
        if(v.size()==2)
        {
            int idx1 = v[0];
            int idx2 = v[1];
            if(s1[idx1]==s2[idx2] && s1[idx2]==s2[idx1])
            return true;
        }
        return false;
    }
};