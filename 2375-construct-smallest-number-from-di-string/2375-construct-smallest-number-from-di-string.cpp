class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> S;
        string num;
        
        for (int i = 0; i <= pattern.size(); i++) {
            S.push(i+'1');
            
            if (i == pattern.size() or pattern[i] == 'I') {
                while (!S.empty()) {
                    num.push_back(S.top());
                    S.pop();
                }
            }
        }
        
        return num;
    }
};


/*

IIIDIDDD

1 2 3 4 3 4 3 2 1

1 2 3 5 4 9 8 7 6

*/