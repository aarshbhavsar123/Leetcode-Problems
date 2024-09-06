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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto it:nums)
        {
            st.insert(it);
        }
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        while(temp!=NULL)
        {
            if(st.find(temp->val)==st.end())
            {
                t->next = new ListNode(temp->val);
                t = t->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }

};