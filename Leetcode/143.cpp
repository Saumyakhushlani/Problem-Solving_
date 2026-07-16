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
    void reorderList(ListNode* head) {
        ListNode* fast=head;        
        ListNode* slow=head;        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        stack<ListNode*> st;

        ListNode* second = slow->next;
        slow->next = nullptr;

        while (second) {
            st.push(second);
            second = second->next;
        }
        ListNode* curr = head;

        while (!st.empty()) {
            ListNode* nxt = curr->next;
            ListNode* last = st.top();
            st.pop();

            curr->next = last;
            last->next = nxt;

            curr = nxt;
        }

        
    }
};