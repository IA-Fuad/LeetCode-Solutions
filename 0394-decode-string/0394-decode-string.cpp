class Solution {
    bool isDigit(char c) {
        return c >= '0' and c <= '9';
    }
    
public:
    string decodeString(string s) {
        stack<string> S;
        string curr;

        for (int i = 0; i <= s.size(); i++) {
            char c = i == s.size() ? ']' : s[i];
          //  cout << c << ' ';
            if (c == '[') {
                S.push(curr);
                curr.clear();
            }
            else if (c == ']') {
                string str = "";
                while (!S.empty() and !isDigit(S.top()[0])) {
                    str = S.top() + str;
                    S.pop();
                }
                if (curr.size() > 0) {
                    str += curr;
                    curr.clear();
                }

               // cout << S.size() << ' ' << S.top() << ' ';
                
                int repeat;
                if (S.empty() or !isDigit(S.top()[0])) repeat = 1;
                else {
                    repeat = stoi(S.top());
                    S.pop();
                }

                string decode = str;
                while (--repeat > 0) {
                    decode += str;
                }

                S.push(decode);
               // cout << decode << endl;
            }
            else {
                if (curr.size() == 0) curr.push_back(c);
                else if (isDigit(c) ^ isDigit(curr[0])) {
                    S.push(curr);
                    curr = c;
                }
                else {
                    curr.push_back(c);
                }
            }
        }

        return S.top();
    }
};