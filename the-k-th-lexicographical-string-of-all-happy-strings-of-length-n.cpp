class Solution {
public:
    void solve(int i, string &s,set<string>&st,int n)
    {
        if(i>=n)
        {
            st.insert(s);
            return ;
        }
        for(char c = 'a';c<='c';c++)
        {
            if(c!=s[i-1])
            {
                s[i] = c;
                solve(i+1,s,st,n);
                s[i] = '*';
            }
        }
    }
    string getHappyString(int n, int k) {
        string s(n,'*');
        set<string>st;
        for(char c = 'a';c<='c';c++)
        {
            s[0] = c;
            solve(1,s,st,n);
        }
        vector<string>v;
        for(auto it:st)
        {
            v.push_back(it);
        }
        return (k>st.size())?"":v[k-1];

    }
};