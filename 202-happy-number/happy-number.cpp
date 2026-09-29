class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;

        while (n > 0) {
            int remain = n % 10;
            sum += remain * remain;
            n = n / 10;
        }

        return sum;
    }
    bool isHappy(int n) { 

        int slow=n;
        int fast=nextNumber(n);

        while(fast != 1 && fast!=slow){
            slow=nextNumber(slow);
            fast=nextNumber(nextNumber(fast));
        }

        return fast == 1;
     }
};