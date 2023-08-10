class Solution {
public:
    int maxDiff(int num) {
        string N = to_string(num);
        int a = INT_MAX, b = INT_MIN;
        
        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                if (y == '0' and N[0] == x) continue;
                string tempN = N;
                for (int k = 0; k < N.size(); k++) {
                    if (N[k] == x) {
                        tempN[k] = y;
                    }
                }
                a = min(a, stoi(tempN));
                b = max(b, stoi(tempN));
            }
        }
        
        return b - a;
    }
};