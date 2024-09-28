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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return NULL;
        ListNode* prevE = NULL;
        ListNode* prevO = NULL;
        ListNode* newHeadE = new ListNode(-1);
        ListNode* te = newHeadE;
        ListNode* newHeadO = new ListNode(-1);
        ListNode* to = newHeadO;
        ListNode* temp = head;
        int i = 0;
        while(temp)
        {
            ListNode* next = temp->next;
            if(i%2==0)
            {
                te->next = temp;
                temp->next = NULL;
                temp = next;
                te=te->next;
            }
            else
            {
                to->next = temp;
                temp->next = NULL;
                temp = next;
                to=to->next;
            }
            i++;
        }
        ListNode* t1 = newHeadE->next;
        ListNode* t2 = newHeadO->next;
        while(t1->next)
        {
            t1=t1->next;
        }
        t1->next = t2;
        return newHeadE->next;
    }
};