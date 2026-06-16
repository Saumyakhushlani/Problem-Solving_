class Solution {
public:
    int sq(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sq(slow);
            fast = sq(sq(fast));
        } while (slow != fast);

        return slow == 1;
    }

    int nextHappy(int N) {
        int num = N + 1;

        while (true) {
            if (isHappy(num))
                return num;
            num++;
        }
    }
};