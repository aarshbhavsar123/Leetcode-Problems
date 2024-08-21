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
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long maxi = INT_MIN;

        while(!q.empty())
        {
            long long first = q.front().second;
            long long second = q.back().second;
            long long s=  q.size();
            maxi = max(maxi,(second-first));

            for(int i = 0;i<s;i++)
            {
                auto top = q.front();
                q.pop();
                if(top.first->left)
                {
                    q.push({top.first->left,((top.second<<1)+(1))});
                }
                if(top.first->right)
                {
                    q.push({top.first->right,((top.second<<1)+(2))});
                }
            }
        }
        return maxi+1;
    }
};