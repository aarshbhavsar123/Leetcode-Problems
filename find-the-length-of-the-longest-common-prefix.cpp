class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<string>s1,s2;
        for(int i = 0;i<n;i++)
        {
            string s = to_string(arr1[i]);
            string x = "";
            for(auto it:s)
            {
                x+=it;
                s1.insert(x);
            }
        }
        for(int i = 0;i<m;i++)
        {
            string s = to_string(arr2[i]);
            string x = "";
            for(auto it:s)
            {
                x+=it;
                s2.insert(x);
            }
        }
        int maxi = 0;
        for(auto it:s1)
        {
            if(s2.find(it)!=s2.end())
            {
                int x = it.length();
                maxi = max(maxi,x);
            }
        }
        return maxi;
    }
};
