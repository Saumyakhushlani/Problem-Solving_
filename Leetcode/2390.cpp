class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for(char c: s){
            if(c=='*')st.pop();
            else st.push(c);
        }
        string k;
        while(!st.empty()){
            k.push_back(st.top());
            st.pop();

        }
        reverse(k.begin(),k.end());
        return k;
    }
};