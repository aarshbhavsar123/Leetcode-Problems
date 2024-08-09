class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        int n = seats.size();
        
        
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                ones.push_back(i);
            }
        }
        
        int ans = 0;
        
        
        for(int i = 0; i < n; i++) {
            if(seats[i] == 0) {
                int left = (lower_bound(ones.begin(), ones.end(), i) == ones.begin()) ? INT_MAX : i - *(prev(lower_bound(ones.begin(), ones.end(), i)));
                int right = (lower_bound(ones.begin(), ones.end(), i) == ones.end()) ? INT_MAX : *lower_bound(ones.begin(), ones.end(), i) - i;
                ans = max(ans, min(left, right));
            }
        }
        
        return ans;
    }
};
