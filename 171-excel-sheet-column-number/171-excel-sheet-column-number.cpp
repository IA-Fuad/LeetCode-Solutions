class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        if (n == 0) return 0;
        int titleNumber = columnTitle[0] - 'A' + 1;
        for (int i = 1; i < n; i++) {
            int c = columnTitle[i] - 'A' + 1;
            
            titleNumber = (titleNumber * 26) + c;
        }
        return titleNumber;
    }
};