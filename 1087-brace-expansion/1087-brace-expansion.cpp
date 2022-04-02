class Solution {
    void rec(vector<string>& ans, vector<vector<char>>& vec, int i, string& s) {
        if (i == vec.size()) {
            ans.push_back(s);
            return;
        }
        
        for (int k = 0; k < vec[i].size(); k++) {
            s.push_back(vec[i][k]);
            rec(ans, vec, i+1, s);
            s.pop_back();
        }
    }
    
public:
    vector<string> expand(string s) {
        istringstream ss(s);
        string x;
        
        vector<vector<char>> vec;
        
        while (getline(ss, x, '}')) {
            istringstream ls(x);
            while (getline(ls, x, '{')) {
                vector<char> chars;
                for (char c : x) {
                    if (c >= 'a' and c <= 'z') {
                        chars.push_back(c);
                    }
                }
                if (chars.size() > 0) {
                    sort(chars.begin(), chars.end());
                    vec.push_back(chars);
                }
            }
        }
        
        vector<string> ans;
        
        bool oneOption = true;
        for (char c : s) {
            if (c == ',') {
                oneOption = false;
                break;
            }
        }
        
        if (oneOption and vec.size() == 1) {
            ans.push_back(s);
            return ans;
        }
        
        string p = "";
        rec(ans, vec, 0, p);
        
        return ans;
    }
};