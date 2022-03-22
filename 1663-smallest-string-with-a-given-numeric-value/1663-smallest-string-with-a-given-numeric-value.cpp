class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        
        while(n) {
            int currentChar = 0;
            while (k - currentChar >= n and currentChar < 26) currentChar++;
            ans += (char)(currentChar+'a'-1);
           // cout << currentChar << ' ';
            k -= currentChar;
            n--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};