class Solution {
    struct Node {
        Node* next[26];
        vector<int> indices;
        bool endMark;
        
        Node() {
            this->endMark = false;
            for (int i = 0; i < 26; i++) {
                this->next[i] = nullptr;
            }
        }
        
        void AddIndex(int index) {
            if (indices.size() < 3) {
                indices.push_back(index);
            }
        }
    } *root;
    
    void addProductToTrie(const string& product, int index) {
        Node* curr = root;
        
        for (char c : product) {
            int x = c - 'a';
            if (!curr->next[x]) {
                curr->next[x] = new Node();
            }
            curr = curr->next[x];
            curr->AddIndex(index);
        }
        curr->endMark = true;
    }
    
    vector<string> getSuggestions(vector<string>& products, const string& word) {
        Node* curr = root;
        vector<string> suggestions;
        priority_queue<int, vector<int>, greater<int>> Q;
        int i = 0;
        
        while (curr) {
            int x = word[i++] - 'a';
            curr = curr->next[x];
            
            if (!curr) {
                return {};
            }
            if (i == word.size()) {
                for (int ind : curr->indices) {
                    suggestions.push_back(products[ind]);
                } 
                break;
            }
        }
        
        return suggestions;
    }
    
    vector<vector<string>> getSuggestedProducts(vector<string>& products, const string& searchWord) {
        for (int i = 0; i < products.size(); i++) {
            addProductToTrie(products[i], i);
        }
        
        vector<vector<string>> suggestedProducts;
        string word;
        
        for (char c : searchWord) {
            word.push_back(c);
            suggestedProducts.push_back(getSuggestions(products, word));
        }
        
        return suggestedProducts;
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        root = new Node();
        return getSuggestedProducts(products, searchWord);
    }
};