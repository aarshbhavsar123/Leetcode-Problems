class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(32, -2);
        int n = s.length();
        v[0] = -1;
        int maxi = 0;
        int mask = 0;
        for (int i = 0; i < n; ++i) 
        {
            char ch = s[i];

            if(s[i]=='a')
            {
                mask ^= 1;
            }
            else if(s[i]=='e')
            {
                mask ^= 2;
            }
            else if(s[i]=='i')
            {
                mask ^= 4;
            }
            else if(s[i]=='o')
            {
                mask ^= 8;
            }
            else if(s[i]=='u')
            {
                mask ^= 16;
            }
            int prev = v[mask];
            if (prev == -2) 
            {
                v[mask] = i;
            }
            else 
            {
                maxi = max(maxi, i - prev);
            }
        }

        return maxi;
    }
};