/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, bool> vis;
        unordered_map<Node*, Node*> clones;
        Node* temp = new Node(node->val);
        clones[node] = temp;
        vis[node] = true;
        queue<pair<Node*, Node*>> q;
        q.push({node, temp});
        while (!q.empty()) 
        {
            auto top = q.front();
            q.pop();
            Node* act = top.first;
            Node* add = top.second;
            for (auto it : act->neighbors) 
            {
                if (!vis[it]) 
                {
                    if (clones.find(it) == clones.end()) 
                    {
                        Node* t = new Node(it->val);
                        clones[it] = t;
                    }
                    add->neighbors.push_back(clones[it]);
                    if (!vis[it]) 
                    {
                        vis[it] = true;
                        q.push({it, clones[it]});
                    }
                } 
                else 
                {
                    add->neighbors.push_back(clones[it]);
                }
            }
        }
        return temp;
    }
};