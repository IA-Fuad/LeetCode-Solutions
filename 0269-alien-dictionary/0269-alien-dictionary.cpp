class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<unordered_set<int>> graph(27);
        vector<int> degree(27);
        vector<bool> mark(27, false);
        int cnt = 0;
        
        for (string& word : words) {
            for (char c : word) {
                if (!mark[c-'a']) cnt++;
                mark[c-'a'] = true;
            }
        }

        for (int i = 0; i < words.size()-1; i++) {
            string a = words[i];
            string b = words[i+1];

            if (a.size() > b.size() and a.rfind(b, 0) == 0) return "";
            for (int k = 0; k < min(a.size(), b.size()); k++) {
                if (a[k] != b[k]) {
                    if (graph[a[k]-'a'].find(b[k]-'a') == graph[a[k]-'a'].end()) {
                        graph[a[k]-'a'].insert(b[k]-'a');
                        degree[b[k]-'a']++;
                    }
                    
                    //cout << a[k] << ' ' << b[k] << ' ' << degree['e'-'a'] << endl;
                    break;
                }
            }
        }
        
        queue<int> leaves;
        
        for (int i = 0; i < 26; i++) {
            if (degree[i] == 0 and mark[i]) {
                leaves.push(i);
            }
        }
        
        string ans;
        
        while (!leaves.empty()) {
            int currSize = leaves.size();
            int u = leaves.front();
            leaves.pop();
            ans.push_back((char)(u+'a'));

            for (int k : graph[u]) {
                degree[k]--;
                //cout << (char)(u+'a') << ' ' << (char)(k+'a') << ' ' << degree[k] << endl;
                if (degree[k] == 0) {
                    leaves.push(k);
                }
            }
        }
        cout << ans << ' ';
        return ans.size() == cnt ? ans : "";
    }
};