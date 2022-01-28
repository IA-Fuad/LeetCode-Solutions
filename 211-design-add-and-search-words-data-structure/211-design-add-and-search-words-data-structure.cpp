class WordDictionary {
    struct Node {
        Node* next[26];
        bool endPoint;
        
        Node() {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
            endPoint = false;
        }
    } *root;
    
    bool searchWord(const string& word, int i, Node* curr) {
        if (i == word.size()) {
            if (curr && curr->endPoint) return true;
            return false;
        }
        if (!curr) return false;
        
        if (word[i] == '.') {
            for (int k = 0; k < 26; k++) {
                if (searchWord(word, i+1, curr->next[k])) {
                    return true;
                }
            }
        }
        else {
            return searchWord(word, i+1, curr->next[word[i]-'a']);
        }
        
        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->next[c-'a']) curr->next[c-'a'] = new Node();
            curr = curr->next[c-'a'];
        }
        curr->endPoint = true;
    }
    
    bool search(string word) {
        return searchWord(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */