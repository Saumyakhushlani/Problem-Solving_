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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* curr = head;
        ListNode* l = nullptr;

        for (int i = 1; i < left; i++) {
            l = curr;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        ListNode* tail = curr;
        int times = right - left + 1;

        while (times--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        tail->next = curr;

        if (l)
            l->next = prev;
        else
            head = prev;
        return head;
    }
};