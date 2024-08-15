class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0;
        unordered_map<int,int>mp;
        int n = bills.size();
        for(int i = 0;i<n;i++)
        {
            int paid = bills[i];
            if(paid == 5)
            {
                mp[5]++;
            }
            if(paid==10)
            {
                if(!mp[5])
                return false;

                else
                {
                    mp[5]--;
                }
                mp[10]++;
            }
            if(paid==20)
            {
                if(mp[5]>0 && mp[10]>0)
                {
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>2)
                {
                    mp[5]-=3;
                }
                else return false;
                mp[20]++;
            }
        }
        return true;
    }
};