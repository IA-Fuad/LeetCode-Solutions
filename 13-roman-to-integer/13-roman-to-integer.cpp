class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> romanNum;
        romanNum["I"] = 1, romanNum["IV"] = 4, romanNum["V"] = 5, romanNum["IX"] = 9, romanNum["X"] = 10, romanNum["XL"] = 40, romanNum["L"] = 50, romanNum["XC"] = 90, romanNum["C"] = 100, romanNum["CD"] = 400, romanNum["D"] = 500, romanNum["CM"] = 900, romanNum["M"] = 1000;
        
        int num = 0;
        
        for (int i = 0; i < s.size(); i++) {
            string roman;
            roman.push_back(s[i]);
            if (i+1 < s.size()) {
                bool takeNext = romanNum.find(roman+s[i+1]) != romanNum.end();
                
                if (takeNext) {
                    roman.push_back(s[i+1]);
                    i++;
                }
            }
            
            num += romanNum[roman];
        }
        
        return num;
    }
};