class Solution {
public:
    int op(char opera,int x,int y)
    {
        if(opera=='+')
        return x+y;
        if(opera=='*')
        return x*y;
        if(opera=='-')
        return x-y;
        return 0;
    }
    bool digit(char c)
    {
        return c>='0' && c<='9';
    }
    vector<int>solve(int i,int j,string str)
    {
        if(i==j)
        {
            return {str[i]-'0'};
        }
        if(j-i==1 && digit(str[j]))
        {
            return {(str[i]-'0')*10+str[j]-'0'};
        }
        
        vector<int>ans;
        for(int k = i;k<j;k++)
        {
            if(!digit(str[k]))
            {
                vector<int>l = solve(i,k-1,str);
                vector<int>r = solve(k+1,j,str);
                int x = l.size();
                int y = r.size();
                for(int z = 0;z<x;z++)
                {
                    for(int q = 0;q<y;q++)
                    {
                        ans.push_back(op(str[k],l[z],r[q]));
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string str) {
        return solve(0,str.size()-1,str);
    }
};