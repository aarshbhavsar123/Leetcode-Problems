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
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            
            int sz = q.size();
            vector<int>v;
            for(int i = 0;i<sz;i++)
            {
                Node* top = q.front();
                q.pop();
                vector<Node*>adj = top->children;
                v.push_back(top->val);
                for(auto it:adj)
                {
                    if(it)
                    {
                        q.push(it);
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};