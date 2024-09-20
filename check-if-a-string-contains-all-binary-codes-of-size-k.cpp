class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;

        int n = s.length();
        for(int i = 0;i<=n-k;i++)
        {
            string sub = s.substr(i,k);
            st.insert(sub);
        }
        for(auto it:st)
        {
            cout<<it<<" "<<endl;
        }
        int x = 1<<k;
        return st.size()==x;
    }
};