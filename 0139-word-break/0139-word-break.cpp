struct Node {
    Node* next[26];
    bool endMark;
    
    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        endMark = false;
    }
} *root;

class Solution {
    void buildTree(Node* node, const string& str) {
        for (char c : str) {
            if (!node->next[c-'a']) {
                node->next[c-'a'] = new Node();
            }
            node = node->next[c-'a'];
        }
        node->endMark = true;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Node();
        for (string& word : wordDict) {
            buildTree(root, word);
        }
        
        int n = s.size();
        vector<bool> dp(n, false);
        
        for (int i = 0; i < n; i++) {
            if (i == 0 or dp[i-1]) {
                auto curr = root;
                for (int j = i; j < n; j++) {
                    curr = curr->next[s[j]-'a'];
                    if (!curr) break;
                    if (curr->endMark) dp[j] = true;
                }
            }
        }
        
        return dp[n-1];
    }
};