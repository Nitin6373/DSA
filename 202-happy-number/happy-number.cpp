class Solution {
public:
    int Find(int a){
        int sum = 0;
        int digit;
        while(a > 0){
            digit = a % 10;
            a = a / 10;
            sum += digit * digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = Find(slow);
            fast = Find(fast);
            fast = Find(fast);

            if(slow == fast && fast != 1){
                return false;
            }
        }
        return true;
    }
};