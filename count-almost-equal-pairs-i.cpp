class Solution {
public:
    bool almostEqual(int x, int y) {
        if (x == y) return true;
        vector<int> v1(6, 0), v2(6, 0);
        int i = 5, j = 5;
        while (x) {
            v1[i] = x % 10;
            i--;
            x /= 10;
        }
        while (y) {
            v2[j] = y % 10;
            j--;
            y /= 10;
        }
        
        vector<int> v3;
        for (int k = 0; k < 6; k++) {
            if (v1[k] != v2[k]) {
                v3.push_back(k);
            }
        }
        
        
        if (v3.size() == 2) {
            int idx1 = v3[0];
            int idx2 = v3[1];
            if (v1[idx1] == v2[idx2] && v1[idx2] == v2[idx1]) {
                return true;
            }
        }
        
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (almostEqual(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};
