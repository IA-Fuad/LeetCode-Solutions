class Solution {
    struct Node {
        string word;
        Node* next[26];
        
        Node() {
            word = "";
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    }*root;
    
    void buildTrie(const string& word) {
        auto curr = root;
        
        for (int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            
            if (!curr->next[c]) {
                curr->next[c] = new Node();
            }
            curr = curr->next[c];
        }
        curr->word = word;
    }
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void findWords(vector<string>& res, vector<vector<char>>& board, int row, int col, Node* node) {
        char currentLetter = board[row][col];
        
        auto currentNode = node->next[currentLetter-'a'];
        
        if (!currentNode) return;
        
        if (currentNode->word != "") {
            res.push_back(currentNode->word);
            currentNode->word = "";
        }

        board[row][col] = 'X';
        
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + row;
            int y = dy[k] + col;
            
            if (x < 0 or y < 0 or x == board.size() or y == board[0].size() or board[x][y] == 'X') continue;
            findWords(res, board, x, y, currentNode);
        }
        
        board[row][col] = currentLetter;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        
        for (string& word : words) {
            buildTrie(word);
        }
        
        vector<string> res;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->next[board[i][j] - 'a']) {
                    findWords(res, board, i, j, root);
                }
            }
        }
        
        return res;
    }
};