class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
      
        vector<int> s(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]){
                s[i]=s[i-1]+1;
            }
            

        }
        for (int i = n-1; i >0; i--) {
            if (ratings[i-1] > ratings[i]){
                
                s[i-1]=max(s[i]+1,s[i-1]);
            }
            

        }
        int candy = 0;
        for (int x : s) {
            candy += x;
        }
        return candy;
    }
};