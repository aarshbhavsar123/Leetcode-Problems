class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        return s;
        vector<string>v(numRows);
        int n = s.length();
        int i = 0;
        bool fl = 1;
        int j = 0;
        while(i<n)
        {
            if(fl)
            {
                v[j].push_back(s[i]);
                j++;
                i++;
                if(j==numRows-1)
                {
                    fl = false;
                }
            }
            else
            {
                v[j].push_back(s[i]);
                i++;
                j--;
                if(j==0)
                {
                    fl = true;
                }
            }
        }
        string ans = "";
        for(auto it:v)
        {
            cout<<it<<endl;
            ans+=it;
        }
        return ans;
    }
};