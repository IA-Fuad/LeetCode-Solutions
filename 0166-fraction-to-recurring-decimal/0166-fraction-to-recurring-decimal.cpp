class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if ((numerator < 0 and denominator > 0) or (numerator > 0 and denominator < 0)) {
            ans.push_back('-');
        }

        int64_t num, den;
        num = labs((int64_t)numerator);
        den = labs((int64_t)denominator);
        int64_t div = num / den;
        int64_t mod = num % den;
        
        if (mod == 0) {
            return ans + to_string(div);
        }
        
        ans += to_string(div) + ".";
        int64_t curr = labs(mod);
        
        vector<int> fractions;
        unordered_map<int, int> fracInd;
        int repeat = -1;
        
        while(curr > 0) {
            curr *= 10;
            
            auto it = fracInd.find(curr);
            if (it != fracInd.end()) {
                repeat = it->second;
                break;
            }
            
            fractions.push_back(abs(curr / den));
            fracInd[curr] = fractions.size() - 1;
            
            curr %= den;
        }
        
        for (int i = 0; i < fractions.size(); i++) {
            if (i == repeat) {
                ans.push_back('(');
            }
            ans += to_string(fractions[i]);
        }
        if (repeat != -1) {
            ans.push_back(')');
        }
        
        return ans;
    }
};