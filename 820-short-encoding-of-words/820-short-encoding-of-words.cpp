class Solution {
    struct Node {
        Node* next[26];
        bool endMark;
        int currentLen;
        
        Node(int currentLen) {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
            endMark = false;
            this->currentLen = currentLen;
        }
    } *root;
    
    void addWord(const string& word) {
        auto curr = root;
        bool addEndMark = false;
        
        for (char c : word) {
            int x = c - 'a';
            addEndMark = false;
            
            if (!curr->next[x]) {
                curr->next[x] = new Node(curr->currentLen + 1);
                addEndMark = true;
            }
            curr->endMark = false;
            curr = curr->next[x];
        }
        if (addEndMark) curr->endMark = true;
    }
    
    int len = 0;
    
    void getReferenceStringLen(Node* curr) {
        if (!curr) return;
        if (curr->endMark) {
            len += curr->currentLen + 1;
        }
        for (int i = 0; i < 26; i++) {
            getReferenceStringLen(curr->next[i]);
        }
    }
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        root = new Node(0);
        
        for (string& word : words) {
            reverse(word.begin(), word.end());
            addWord(word);
        }
        
        getReferenceStringLen(root);
        
        return len;
    }
};