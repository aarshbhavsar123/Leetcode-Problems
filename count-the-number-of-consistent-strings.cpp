class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>arr(26,0);
        for (auto c : allowed) 
        {
            arr[c - 'a'] = 1;
        }
        
        int count = 0;
        for (auto it : words) 
        {
            int fl = 1;
            for (auto c : it) 
            {
                if (arr[c - 'a'] == 0) 
                {
                    fl = 0;
                    break;
                }
            }
            count += fl;
        }
        return count;
    }
};