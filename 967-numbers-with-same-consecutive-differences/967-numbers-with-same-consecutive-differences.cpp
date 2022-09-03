class Solution {
    void rec(vector<int>& ans, int num, int len, int diff) {
        if (len == 0) {
            ans.push_back(num);
            return;
        }
        
        int lastDigit = num % 10;
        if (lastDigit + diff < 10) {
            num = (num * 10) + (lastDigit + diff);
            rec(ans, num, len-1, diff);
            num /= 10;
        }
        if (diff > 0 and lastDigit - diff >= 0) {
            num = (num * 10) + (lastDigit - diff);
            rec(ans, num, len-1, diff);
            num /= 10;
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for (int i = 1; i < 10; i++) {
            rec(ans, i, n-1, k);
        }
        
        return ans;
    }
};