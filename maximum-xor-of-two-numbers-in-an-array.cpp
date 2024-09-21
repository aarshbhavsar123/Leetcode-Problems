class Node {
public:
    vector<Node*> links;
    Node() {
        links.resize(2, NULL);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;  
            if (node->links[bit] == NULL) {
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
            if (node->links[1 - bit] != NULL) {
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
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        int ans = 0;  
        for (auto it : nums) {
            t->insert(it);
            ans = max(ans, t->getMax(it));
        }
        return ans;
    }
};
