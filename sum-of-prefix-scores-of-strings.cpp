class Node {
public:
    int count;
    unordered_map<char, Node*> links;
    Node() {
        count = 0;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* node = root;
        for (auto it : s) {
            if (node->links.find(it) == node->links.end()) {
                node->links[it] = new Node();
            }
            node = node->links[it];
            node->count++;
        }
    }

    int getSum(string s) {
        int sum = 0;
        Node* node = root;
        for (auto it: s) {
            if (node->links.find(it) != node->links.end()) {
                node = node->links[it];
                sum += node->count;
            }
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for (auto it : words) {
            t->insert(it);
        }

        vector<int> result(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            result[i] = t->getSum(words[i]);
        }
        return result;
    }
};
