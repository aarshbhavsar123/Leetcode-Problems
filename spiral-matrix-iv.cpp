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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int layers = min((m + 1) / 2, (n + 1) / 2);
        ListNode* curr = head;
        for (int k = 0; k < layers; k++) {
            for (int j = k; j < n - k && curr; j++) {
                ans[k][j] = curr->val;
                curr = curr->next;
            }
            for (int i = k + 1; i < m - k && curr; i++) {
                ans[i][n - 1 - k] = curr->val;
                curr = curr->next;
            }
            for (int j = n - k - 2; j > k && curr; j--) {
                ans[m - k - 1][j] = curr->val;
                curr = curr->next;
            }
            for (int i = m - 1 - k; i > k && curr; i--) {
                ans[i][k] = curr->val;
                curr = curr->next;
            }
            if (!curr) break;
        }
        return ans;
        
    }
};