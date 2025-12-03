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
        ListNode* odd = new ListNode(-1);
        ListNode* temp1 = odd;
        ListNode* even = new ListNode(-1);
        ListNode* temp2 = even;
        while(head){
            temp1->next=head;
            temp1=temp1->next;
            if(head->next){
                temp2->next=head->next;
                temp2=temp2->next;
            }
            if (head->next) 
                head = head->next->next;
            else break;
        }
        temp2->next = NULL;
        temp1->next=even->next;
        return odd->next;
    }
};