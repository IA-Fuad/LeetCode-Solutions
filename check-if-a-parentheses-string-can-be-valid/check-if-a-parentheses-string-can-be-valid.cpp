class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n&1) return false;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1' && s[i] == '(') left++;
            else if ((s[i] == ')' || locked[i] == '0') && left > 0) {
                // locked[i] = '1'; 
                // s[i] = '.'; 
                left--;
            }
        }
       // cout << left << endl;
        if (left > 0) return false;
        for (int i = n-1; i >= 0; i--) {
            if (locked[i] == '1' && s[i] == ')') right++;
            else if ((s[i] == '(' || locked[i] == '0') && right > 0) {
                right--;
            }
        }
        //cout << right << endl;
        if (right > 0) return false;
        return true;
    }
};