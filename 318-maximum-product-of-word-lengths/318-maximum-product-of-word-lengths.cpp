class Solution {
    int getBitmask(string& word) {
        int mask = (1 << 26) - 1;
        unordered_set<char> s(word.begin(), word.end());
        for (char c : s) {
            int x = c - 'a';
            mask = mask ^ (1 << x);
        }
        return mask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& x, string& y) {
           return x.size() > y.size(); 
        });

        unordered_map<string, int> bitmaskToWord;
        
        for (string& word : words) {
            int mask = getBitmask(word);
            bitmaskToWord[word] = mask;
           // cout << mask << ' ';
        }
        
        int mask = (1 << 26) - 1, product = 0;
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if ((bitmaskToWord[words[i]] | bitmaskToWord[words[j]]) == mask) {
                    //cout << words[i] << ' ' << words[j] << endl;
                    product = max(product, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return product;
    }
};