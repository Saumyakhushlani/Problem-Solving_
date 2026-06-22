/* Structure of a Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* reverseBetween(int left, int right, Node* head) {
        // code here
        if (!head || left == right) return head;

        Node* curr = head;
        Node* l = nullptr;

        for (int i = 1; i < left; i++) {
            l = curr;
            curr = curr->next;
        }

        Node* prev = nullptr;
        Node* tail = curr;
        int times = right - left + 1;

        while (times--) {
            Node* temp = curr->next;
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