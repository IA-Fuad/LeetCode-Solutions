class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> digit;

        for (int i = 0; i < n && k > 0; i++) {
            while (k > 0 && !digit.empty() && num[digit.top()] > num[i]) {
                num[digit.top()] = 'X';
                digit.pop();
                k--;
            }
            digit.push(i);
        }
        while (k > 0 && !digit.empty()) {
            num[digit.top()] = 'X';
            digit.pop();
            k--;
        }
        
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (num[i] == 'X' || (num[i] == '0' && ans.size() == 0)) {
                continue;
            }
            ans += num[i];
        }
        
        return ans.size() == 0 ? "0" : ans;
    }
};