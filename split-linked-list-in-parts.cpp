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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int>v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        vector<vector<int>>v2;
        if(n/k==0)
        {
            vector<vector<int>>ans(n,vector<int>(1));
            for(int i = 0;i<n;i++)
            {
                ans[i][0] = v[i];
            }
            v2 = ans;
        }
        else
        {   
            int x = n-(n/k)*k;
            int i = 0;
            vector<int>v3;
            int prev = 0;
            
            while(i<n)
            {
                v3.push_back(v[i]);
                if(i-prev==n/k-1 && x>0 && i+1<n)
                {
                    x--;
                    i++;
                    v3.push_back(v[i]);
                    prev = i+1;
                    v2.push_back(v3);
                    v3.clear();
                }
                else if(i-prev==n/k-1 && x==0)
                {
                    v2.push_back(v3);
                    v3.clear();
                    prev = i+1;
                }
                
                i++;
            }
        }
        vector<ListNode*>ans(k);
        for(int i = 0;i<v2.size();i++)
        {
            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;
            vector<int>v = v2[i];
            for(auto jt:v)
            {
                temp->next = new ListNode(jt);
                temp = temp->next;
            }
            ans[i] = dummy->next;
        }
        return ans;
    }
};