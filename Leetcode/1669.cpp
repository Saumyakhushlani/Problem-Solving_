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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* al = list1;
        ListNode* bl = list1;
        ListNode* temp = list2;
        for(int i=0;i<a-1 ;i++){
            al=al->next;
        }
        for(int i=0;i<=b;i++){
            bl=bl->next;
        }
        al->next=list2;
        while(temp->next){
            temp=temp->next;

        }
        
        temp->next=bl;
        return list1;

    }
};