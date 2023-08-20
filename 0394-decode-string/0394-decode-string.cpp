class Solution {
    int k = 0;
    
public:
    string decodeString(string s) {
        string decode;
        while (k < s.size()) {
            if (!isdigit(s[k])) {
                if (s[k] == ']') {
                    k++;
                    break;
                }
                decode.push_back(s[k++]);
            }
            else {
                string digit;
                while (s[k] != '[') {
                    digit.push_back(s[k++]);
                }
                k++;
                
                int repeat = stoi(digit);
                string ds = decodeString(s);
                while (--repeat >= 0) {
                    decode += ds;
                }
            }
        }
        return decode;
    }
};