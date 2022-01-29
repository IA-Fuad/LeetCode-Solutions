class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, int> index;
        int ind = 0;
        
        for (string s : strings) {
            string t = s;
            auto indx = index.find(s);
            if (indx == index.end()) {
                ans.push_back({s});
                index[s] = ind;
                while (true) {
                    for (int i = 0; i < s.size(); i++) {
                        if (t[i] == 'z') {
                            t[i] = 'a';
                        }
                        else {
                             t[i]++;   
                        }
                    }
                    if (index.find(t) != index.end()) break;
                    index[t] = ind;
                }
                ind++;
            }
            else {
                ans[indx->second].push_back(s);
            }
        }
        
        return ans;
    }
};