/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find(int data,TreeNode* root,vector<TreeNode*>&v)
    {
        if(root==NULL)
        return ;

        if(data==root->val)
        {
            v.push_back(root);
        }
        find(data,root->left,v);
        find(data,root->right,v);
    }
    bool dfs(ListNode* head,TreeNode* r)
    {
        if(head==NULL)
        return true;

        if(r==NULL)
        {
            return false;
        }

        if(head->val!=r->val)
        return false;

        return dfs(head->next,r->left)||dfs(head->next,r->right);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL)
        return true;

        int data = head->val;
        vector<TreeNode*>v;
        find(data,root,v);
        if(v.size()==0)
        {
            return false;
        }
        for(auto it:v)
        {
            TreeNode* r = it;
            if(dfs(head,r))
            return true;
        }
        return false;
    }
};