/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
        return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        int maxi = INT_MIN;
        int level = 0;
        while(!q.empty()){
            
            int sz = q.size();
            level++;
            vector<int>v;
            for(int i = 0;i<sz;i++)
            {
                Node* top = q.front();
                q.pop();
                vector<Node*>adj = top->children;
                for(auto it:adj)
                {
                    if(it)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return level;
    }
};