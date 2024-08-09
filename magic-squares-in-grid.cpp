class Solution {
public:
    bool isValid(vector<vector<int>>&sub)
    {
        set<int>st3;
        for(int i = 0;i<sub.size();i++)
        {
            for(int j = 0;j<sub.size();j++)
            {
                if(sub[i][j]>9||sub[i][j]==0)
                return false;
                st3.insert(sub[i][j]);
            }
        }
        if(st3.size()!=9)
        return false;
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i<sub.size();i++)
        {
            sum1+=sub[i][i];
            sum2+=sub[i][2-i];
        }
        set<int>st1,st2;
        for(int i = 0;i<3;i++)
        {
            int sum = 0;
            for(int j = 0;j<3;j++)
            {
                sum+=sub[i][j];
            }
            st1.insert(sum);
        }
        for(int i = 0;i<3;i++)
        {
            int sum = 0;
            for(int j = 0;j<3;j++)
            {
                sum+=sub[j][i];
            }
            st2.insert(sum);
        }
        if(st1.size()==1 && st2.size()==1 && sum1==sum2 && *st1.begin()==sum1 && *st2.begin()==sum1)
        return 1;
        
        
        return 0;
    }
    void print(vector<vector<int>>sub)
    {
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                cout<<sub[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        if(n<3||m<3)
        return 0;
        for(int i = 0;i<=n-3;i++)
        {
            for(int j = 0;j<=m-3;j++)
            {
                vector<vector<int>>sub(3,vector<int>(3));
                for(int k = i;k<i+3;k++)
                {
                    for(int l = j;l<j+3;l++)
                    {
                        sub[k-i][l-j] = grid[k][l];
                    }
                }
                print(sub);
                cout<<endl;
                if(isValid(sub))
                {
                    count++;
                }
            }
        }
        return count;
    }
};