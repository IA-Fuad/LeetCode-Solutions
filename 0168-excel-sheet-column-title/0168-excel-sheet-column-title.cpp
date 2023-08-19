class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;
        
        while (columnNumber > 0) {
            columnNumber--;
            int ind = columnNumber % 26;
            title.push_back(ind + 'A');
            columnNumber /= 26;
        }
        
        reverse(title.begin(), title.end());
        
        return title;
    }
};