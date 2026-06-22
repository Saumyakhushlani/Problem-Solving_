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
    void reverse(ListNode* head, int k){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(k--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* left=head;
        ListNode* right=head;
        ListNode* res=nullptr;
        ListNode* prevleft=nullptr;
        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right==nullptr)break;
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                reverse(left,k);
                if(prevleft) prevleft->next=right;
                prevleft=left;
                if(res==nullptr) res=right;
                left = nextleft;
            }else{
                if(prevleft){
                    prevleft->next=left;
                }
                if(res==nullptr) res=left;
                break;
            }
        }
        return res;
    }
};