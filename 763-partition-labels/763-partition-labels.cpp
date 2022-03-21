class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastCharPosition(26, -1);
        for (int i = 0; i < s.size(); i++) {
            lastCharPosition[s[i]-'a'] = i;
        }
        
        vector<int> labels;
        
        for (int i = 0, j = 0, k = 0; i < s.size(); i++) {
            j = max(j, lastCharPosition[s[i]-'a']);
            if (i == j) {
                labels.push_back(j - k + 1);
                k = i + 1;
            }
        }
        
        return labels;
    }
};

/*

ababcbacadefegdehijhklij
               ^      
               ^

*/