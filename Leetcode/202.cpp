class Solution {
public:
    int sq(int n){
        int sum=0;
        while(n>0){
        int k =n%10;
            sum+=k*k;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(fast!=1){
            slow=sq(slow);
            fast=sq(sq(fast));
            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};