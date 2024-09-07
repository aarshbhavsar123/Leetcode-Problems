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
    unordered_map<TreeNode*,int>dp;
    
    int dfs(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int count = 0;
        if(root->val == 1)
        count = 1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return dp[root] = count+l+r;
    }
    TreeNode* dfs2(TreeNode* root)
    {
        if(root==NULL)
        return NULL;
        if(dp[root]==0)
        return NULL;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = dfs2(root->left);
        newRoot->right = dfs2(root->right);
        return newRoot;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        int x = dfs(root);
        TreeNode* ans = dfs2(root);
        return ans;
    }
};