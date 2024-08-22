class Solution {
public:
    int findComplement(int num) {
        int x = num;
        vector<int>v;
        while(x)
        {
            v.push_back(!(x%2));
            x/=2;
        }
        int ans = 0;
        reverse(v.begin(),v.end());
        for(int i = v.size()-1;i>=0;i--)
        {
            ans+=v[i]*(1<<(v.size()-i-1));
        }
        return ans;
    }
};