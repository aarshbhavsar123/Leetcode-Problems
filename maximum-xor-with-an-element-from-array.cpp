struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2; 
    }
};

static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Node {
public:
    vector<Node*> links;
    Node() {
        links.resize(2, nullptr);
    }
};

class trie {
public:
    Node* root;
    trie() {
        root = new Node();
    }
    
    void insert(int x) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->links[bit] == nullptr) {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }

    int getMax(int x) {
        Node* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->links[1 - bit] != nullptr) {
                maxi |= (1 << i);
                node = node->links[1 - bit];
            } else {
                node = node->links[bit];
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        vector<pair<int, int>> mp(n);
        
        for (int i = 0; i < n; i++) {
            mp[i] = {queries[i][1], i};
        }
        
        sort(nums.begin(), nums.end());
        sort(mp.begin(), mp.end());
        
        trie* t = new trie();
        int j = 0;

        for (auto[mi, index] : mp) {
            while (j < nums.size() && nums[j] <= mi) {
                t->insert(nums[j]);
                j++;
            }
            ans[index] = (j == 0 ? -1 : t->getMax(queries[index][0]));
        }
        
        return ans;
    }
};
