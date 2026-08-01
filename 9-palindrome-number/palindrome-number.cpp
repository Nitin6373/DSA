class Solution {
public:
    bool isPalindrome(int x) {
        long temp = 0;
        int x2 = x;
        while (x > 0) {
            temp += (x % 10);
            temp *= 10;
            x /= 10;
        }
        temp /= 10;
        if (x2 == temp)
            return true;
        else
            return false;
    }
};