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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* head2=new ListNode(0);
        ListNode* temp2=head2;
        while(temp){
            int sum=0;
            while(temp->val!=0){

                sum+=temp->val;
                temp=temp->next;
            }
            if(temp->val==0){
                temp2->next=new ListNode(sum);
                sum=0;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
            return head2->next;
    }
};