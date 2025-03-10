class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool>vis(n,false);
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            bool fl = true;
            for(int j = 0;j<n;j++)
            {
                if(fruits[i]<=baskets[j] && !vis[j])
                {
                    vis[j] = true;
                    fl = false;
                    break;
                }
            }
            if(fl)
            {
                count++;
            }
        }
        return count;
    }
};