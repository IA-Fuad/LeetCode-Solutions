class Solution {
    pair<int, string> getRoman(vector<pair<int, string>>& numRoman, int num) {
        int left = 0, right = numRoman.size()-1, mid, ind = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (numRoman[mid].first == num) {
                return numRoman[mid];
            }
            if (numRoman[mid].first > num) {
                right = mid - 1;
            }
            else {
                ind = mid;
                left = mid + 1;
            }
        }
        
        return numRoman[ind];
    }
    
public:
    string intToRoman(int num) {
        vector<pair<int, string>> numRoman = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        
        string ans;
        
        while (num > 0) {
            auto roman = getRoman(numRoman, num);
            
            ans.append(roman.second);
            num -= roman.first;
        }
        
        return ans;
    }
};