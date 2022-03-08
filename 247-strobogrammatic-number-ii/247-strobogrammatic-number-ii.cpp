class Solution {
    int stbgNums[5] = {0,1,6,8,9};
    char reverseMap[120];
    
    string getStrobogrammaticNumber(const string& firstHalf, bool isOdd = false) {
        string strobogrammaticNumber = firstHalf;
        int starFrom = isOdd ? firstHalf.size()-2 : firstHalf.size()-1;
        
        for (int i = starFrom; i >= 0; i--) {
            char c = reverseMap[firstHalf[i]];
            strobogrammaticNumber += c;
        }
        
        return strobogrammaticNumber;
    }
    
    void rec(vector<string>& ans, string& num, int n) {
        if (num.size() == n / 2) {
            if (n&1) {
                ans.push_back(getStrobogrammaticNumber(num+'0', true));
                ans.push_back(getStrobogrammaticNumber(num+'1', true));
                ans.push_back(getStrobogrammaticNumber(num+'8', true));
            }
            else {
                ans.push_back(getStrobogrammaticNumber(num));
            }
            return;
        }
        
        for (int i = 0; i < 5; i++) {
            if (num.size() == 0 and i == 0) continue;
            num.push_back((char)(stbgNums[i]+'0'));
            rec(ans, num, n);
            num.pop_back();
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) return {"0", "1", "8"};
        vector<string> ans;
        string num;
        reverseMap['0'] = '0', reverseMap['1'] = '1', reverseMap['6'] = '9', reverseMap['8'] = '8', reverseMap['9'] = '6';
        rec(ans, num, n);
        return ans;
    }
};

/*

0 -> 0
1 -> 1
6 -> 9
8 -> 8
9 -> 6

689

*/