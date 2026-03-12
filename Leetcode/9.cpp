class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long temp=0;
        long long original =x;
        while(x>0){
            temp=temp*10+x%10;
            x/=10;
        }
        if (original==temp) return true;
        return false;

    }
};