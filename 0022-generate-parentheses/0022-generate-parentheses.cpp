class Solution {
    void rec(int n, vector<string>& pars, string& par, int open, int close) {
        if (par.size() == n * 2) {
            pars.push_back(par);
            return;
        }
        
        if (open < n) {
            par.push_back('(');
            rec(n, pars, par, open + 1, close);
            par.pop_back();
        }
        if (close < open) {
            par.push_back(')');
            rec(n, pars, par, open, close + 1);
            par.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string par;
        vector<string> pars;
        
        rec(n, pars, par, 0, 0);
        
        return pars;
    }
};