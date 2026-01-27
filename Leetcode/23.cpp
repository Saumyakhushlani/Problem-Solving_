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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        for (auto list : lists) {
            while (list) {
                mp[list->val]++;
                list = list->next;
            }
        }
        for (auto p : mp) {
            int value = p.first;
            int count = p.second;
            while (count--) {
                pq.push(value);
            }
        }

        ListNode* dummy = new ListNode(-1); 
        ListNode* temp = dummy;

        while (!pq.empty()) {
            int value = pq.top();
            pq.pop();

            temp->next = new ListNode(value); 
            temp = temp->next;                
        }

        return dummy->next;
    }
};