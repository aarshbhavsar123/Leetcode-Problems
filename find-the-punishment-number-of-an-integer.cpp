class Solution {
public:
    bool check(string s,int y)
    {
        if(s=="" && y==0)
        return 1;
        if(y<0)
        return 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            string sub = s.substr(0, i + 1);
            string sub2 = s.substr(i + 1); 
            int x1 = stoi(sub);
            if(check(sub2,y-x1))
            return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1;i<=n;i++)
        {
            string z = to_string(i*i);
            if(check(z,i))
            {
                cout<<i<<" ";
                sum+=(i*i);
            }
        }
        return sum;
    }
};