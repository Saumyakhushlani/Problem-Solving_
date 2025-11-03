/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int carry = 0;

        while (temp) {
            int val = temp->val * 2 + carry;
            temp->val = val % 10;
            carry = val / 10;

            if (!temp->next) {       
                if (carry) {
                    temp->next = new ListNode(carry);
                    carry = 0;
                }
                break;                 
            }
            temp = temp->next;
        }

        head = reverse(head);
        return head;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};