/* Node Structure
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    void reorderList(Node* head) {
        // code here
         Node* fast=head;        
        Node* slow=head;        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        stack<Node*> st;

        Node* second = slow->next;
        slow->next = nullptr;

        while (second) {
            st.push(second);
            second = second->next;
        }
        Node* curr = head;

        while (!st.empty()) {
            Node* nxt = curr->next;
            Node* last = st.top();
            st.pop();

            curr->next = last;
            last->next = nxt;

            curr = nxt;
        }

    }
};