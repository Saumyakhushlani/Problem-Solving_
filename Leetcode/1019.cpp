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
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> ans;
        while(head){
            ListNode* temp = head;
            int v=head->val;
            int found=0;
            while(temp){
                if(temp->val>v){
                    ans.push_back(temp->val);
                    found=1;
                    break;
                }else{
                    temp=temp->next;
                }
            }
            if(found==0){
                ans.push_back(0);
            }
            head=head->next;
        }
        return ans;
    }
};