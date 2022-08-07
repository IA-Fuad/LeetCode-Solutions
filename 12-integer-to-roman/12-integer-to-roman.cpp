class Solution {
    pair<int, string> getRoman(vector<pair<int, string>>& numRoman, int num, int& lastIndex) {
        for (int i = lastIndex; i >= 0; i--) {
            if (numRoman[i].first <= num) {
                lastIndex = i;
                return numRoman[i];
            }
        }
        return {};
    }
    
public:
    string intToRoman(int num) {
        vector<pair<int, string>> numRoman = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        
        string ans;
        int lastIndex = numRoman.size() - 1;
        
        while (num > 0) {
            auto roman = getRoman(numRoman, num, lastIndex);
            
            ans.append(roman.second);
            num -= roman.first;
        }
        
        return ans;
    }
};