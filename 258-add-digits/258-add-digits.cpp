class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
public:
    int addDigits(int num) {
        int sum = digitSum(num);
        if (sum > 9) {
            return addDigits(sum);
        }
        return sum;
    }
};