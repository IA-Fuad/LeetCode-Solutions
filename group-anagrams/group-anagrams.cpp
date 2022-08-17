class Solution {
    string getKey(const string& str) {
        vector<int> charCount(26, 0);
        for (char c : str) {
            charCount[c-'a']++;
        }
        string key;
        for (char c = 'a'; c <= 'z'; c++) {
            key += c;
            key += to_string(charCount[c-'a']);
        }
        return key;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        
        for (const string& str : strs) {
            string key = getKey(str);
            anagrams[key].push_back(str);
        }
        
        vector<vector<string>> groups;
        
        for (auto group : anagrams) {
            groups.push_back(group.second);
        }
        
        return groups;
    }
};