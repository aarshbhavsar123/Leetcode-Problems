class Node {
public:
    vector<Node*> adj;
    
    Node() {
        adj.resize(10, NULL);  
    }
};

class trie {
public:
    Node* root;
    
    trie() {
        this->root = new Node();
    }
    
    void insert(int x) {
        Node* node = root;
        string str = to_string(x);
        int n = str.length();
        
        for (int i = 0; i < n; i++) {
            int y = str[i] - '0';
            if (node->adj[y] == NULL) {  
                node->adj[y] = new Node();
            }
            node = node->adj[y];
        }
    }
};

class Solution {
public:
    void dfs(Node* root, vector<int>& v, string& s) {
        for (int j = 0; j < 10; j++) {
            if (root && root->adj[j] != NULL) {
                s.push_back(j + '0');
                v.push_back(stoi(s));
                dfs(root->adj[j], v, s);
                s.pop_back();
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        trie* t = new trie();
        
        for (int i = 1; i <= n; i++) {
            t->insert(i);
        }
        
        string s = "";
        vector<int> v;
        
        for (int i = 1; i < 10; i++) {
            if (t->root->adj[i] != NULL) {
                s.push_back(i + '0');
                v.push_back(stoi(s));
                dfs(t->root->adj[i], v, s);
                s.pop_back();
            }
        }
        
        for (auto it : v) {
            cout << it << " ";
        }
        cout << endl;

        return v;
    }
};
