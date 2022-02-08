class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int rec(int num) {
        int sum = digitSum(num);
        if (sum > 9) {
            return rec(sum);
        }
        return sum;
    }
    
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = num % 9;
        return sum == 0 ? 9 : sum;
    }
};