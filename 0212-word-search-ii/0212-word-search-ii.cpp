class Solution {
    struct Node {
        Node* next[26];
        bool endMark;
        string word;
        
        Node() {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
            endMark = false;
        }
    } *root;
    
    void addWord(const string& word) {
        auto curr = root;
        
        for (int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if (!curr->next[c]) {
                curr->next[c] = new Node();
            }
            curr = curr->next[c];
        }
        curr->endMark = true;
        curr->word = word;
    }
    
    int dir[4][4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    void searchWords(vector<string>& foundWords, vector<vector<char>>& board, int i, int j, Node* curr) {
        if (i < 0 or j < 0 or i == board.size() or j == board[0].size() or board[i][j] == 'X') return;
        int c = board[i][j] - 'a';
        if (!curr->next[c]) return;
        curr = curr->next[c];
        board[i][j] = 'X';
        
        if (curr->endMark) {
            foundWords.push_back(curr->word);    
            curr->endMark = false;
        }
        
        for (int d = 0; d < 4; d++) {
            searchWords(foundWords, board, i+dir[d][0], j+dir[d][1], curr);
        }
        
        board[i][j] = (char)(c + 'a');
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        
        for (string& word : words) {
            addWord(word);
        }
        
        vector<string> foundWords;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int c = board[i][j] - 'a';
                if (root->next[c]) {
                    searchWords(foundWords, board, i, j, root);
                }
            }
        }
        
        return foundWords;
    }
};