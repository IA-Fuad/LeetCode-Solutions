class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> S;
        
        for (int ast : asteroids) {
            while (!S.empty() and (S.top() > 0 and ast < 0) and abs(S.top()) < abs(ast)) {
                S.pop();
            }
            if (S.empty()) {
                S.push(ast);
            }
            else {
                if (!(S.top() > 0 and ast < 0)) {
                    S.push(ast);
                }
                else if (abs(S.top()) == abs(ast)) {
                    S.pop();
                }
                else if (abs(S.top()) < abs(ast)) {
                    S.push(ast);
                }
            }
        }
        
        if (S.empty()) return {};
        
        int n = S.size();
        vector<int> ans(n);
        while (!S.empty()) {
            ans[--n] = S.top();
            S.pop();
        }
        
        return ans;
    }
};