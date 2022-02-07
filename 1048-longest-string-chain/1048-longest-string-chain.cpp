class Solution {
    bool isPredecessor(const string& a, const string& b) {
        if (a.size() == b.size()) {
            return false;
        }
        int i, j;
        for (i = 0, j = 0; i < a.size() && j < b.size(); j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }

        return i == a.size();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> longestChains(n, 1);

        int longestChain = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (words[j].size() < words[i].size()-1) {
                    break;
                }
                if (isPredecessor(words[j], words[i]) && longestChains[j] + 1 > longestChains[i]) {
                    longestChains[i] = longestChains[j] + 1;
                }
            }
            longestChain = max(longestChain, longestChains[i]);
        }
        
        return longestChain;
    }
    
    bool static cmp(string& x, string& y) {
        return x.size() < y.size();
    }
};