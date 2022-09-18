class Solution {
    struct Node {
        Node* next[26];
        vector<int> indices;
        vector<int> pIndices;
        
        Node() {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    } *root;
    
    bool isPalindrome(const string& word, int i, int j) {
        for (; i < j; i++, j--) {
            if (word[i] != word[j]) return false;
        }
        return true;
    }
    
    void addWord(const string& word, int ind) {
        auto curr = root;
        
        if (isPalindrome(word, 0, word.size()-1)) curr->pIndices.push_back(ind);
        
        for (int i = word.size()-1; i >= 0; i--) {
            int x = word[i] - 'a';
            if (!curr->next[x]) {
                curr->next[x] = new Node();
            }
            curr = curr->next[x];
            
            if (i > 0 and isPalindrome(word, 0, i-1)) {
                curr->pIndices.push_back(ind);
            }
        }
        curr->indices.push_back(ind);
    }

    vector<vector<int>> ans;
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new Node();
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            addWord(words[i], i);
        }
        
        for (int i = 0; i < n; i++) {
            auto curr = root;
            int m = words[i].size();

            for (int k = 0; k < m; k++) {
                int x = words[i][k] - 'a';
                auto& indices = curr->indices;
                curr = curr->next[x];
                
                if (isPalindrome(words[i], k, m-1)) {
                    for (int j : indices) {
                        if (i == j) continue;
                        ans.push_back({i, j});
                    }
                }
                if (curr and k == m-1) {
                    for (int j : curr->indices) {
                        if (i == j) continue;
                        ans.push_back({i, j});
                    }
                    for (int j : curr->pIndices) {
                        if (i == j) continue;
                        ans.push_back({i, j});
                    }
                }
                
                if (!curr) break;
            }
        }
        
        for (int i : root->indices) {
            for (int j : root->pIndices) {
                if (i == j) continue;
                ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};