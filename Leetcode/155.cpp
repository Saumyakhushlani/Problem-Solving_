class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        if (!st.empty()) {
            int i = st.top().second;
            i = min(i, val);
            pair<int, int> p = {val, i};
            st.push(p);
        } else {
            pair<int, int> p = {val, val};
            st.push(p);
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        st.pop();
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */