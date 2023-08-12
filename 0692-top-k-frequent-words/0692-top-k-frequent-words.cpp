class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> wordCount;
        priority_queue<pair<int, string>> Q;
        
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (pair<string, int> wc : wordCount) {
            Q.push({-wc.second, wc.first});
            if (Q.size() > k) Q.pop();
        }
        
        vector<string> topKWords(k);
        while (!Q.empty()) {
            topKWords[--k] = Q.top().second;
            Q.pop();
        }

        return topKWords;
    }
};