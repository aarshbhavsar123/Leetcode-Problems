class Solution {
public:
    void solve(int i,vector<int>&v,int k,string &s,int n,vector<int>&fact)
    {
        if(i==n-1)
        {
            s+=to_string(v.back());
            return;
        }
        int block = k/fact[n-i-1];
        if(k%fact[n-i-1]==0)
        block--;
        s+=to_string(v[block]);
        v.erase(v.begin()+block);
        k-=block*fact[n-i-1];
        solve(i+1,v,k,s,n,fact);
    }
    string getPermutation(int n, int k) {
        vector<int>v;
        vector<int>fact = {1,1,2,6,24,120,720,5040,40320,362880};
        for(int i = 1;i<=n;i++)
        {
            v.push_back(i);
        }
        string ans = "";
        solve(0,v,k,ans,n,fact);
        return ans;
    }
};