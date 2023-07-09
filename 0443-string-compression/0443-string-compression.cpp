class Solution {
public:
    int compress(vector<char>& chars) {
        int newLen = 0;
        for (int i = 0, j; i < chars.size(); ) {
            int groupLen = 1;
            for (j = i+1; j < chars.size() and chars[i] == chars[j]; j++) {
                groupLen++;
            }
            chars[newLen++] = chars[i];
            
            if (groupLen > 1) {
                string sLen = to_string(groupLen);
                for (char c : sLen) {
                    chars[newLen++] = c;
                }
            }
            i += groupLen;
        }
        
        return newLen;
    }
};