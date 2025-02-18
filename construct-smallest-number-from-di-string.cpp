class Solution {
public:
    unordered_map<int,bool>vis;
    string mini = "99999999";
    void solve(string &s,string pat,set<string>&st,int i,int n)
    {
        if(i>=n+1)
        {
            mini = min(mini,s);
            return ;
        }
        if(pat[i-1]=='I')
        {
            int x = s[i-1]-'0';
            for(int k = x+1;k<=9;k++)
            {
                if(!vis[k+'0'])
                {
                    vis[k+'0'] = true;
                    s[i] = k+'0';
                    solve(s,pat,st,i+1,n);
                    s[i] = '*';
                    vis[k+'0'] = false;
                }
                
            }
        }
        else
        {
            int x = s[i-1]-'0';
            for(int k = 1;k<x;k++)
            {
                if(!vis[k+'0'])
                {
                    vis[k+'0'] = true;
                    s[i] = k+'0';
                    solve(s,pat,st,i+1,n);
                    s[i] = '*';
                    vis[k+'0'] = false;
                }
                
            }
        }
    }
    string smallestNumber(string pattern) {
        int n = pattern.length();
       string s(n+1,'*');
       set<string>st;
       for(int i = 1;i<=9;i++)
       {

            s[0] = i+'0';
            vis[s[0]] = true;
            solve(s,pattern,st,1,n);
            vis[s[0]] = false;
       }
       
       return mini;
    }
};