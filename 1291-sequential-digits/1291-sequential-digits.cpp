class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int i = 1; i <= 8; i++) q.push(i);
        
        vector<int> ans;
        
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            
            int x = (n+1) % 10;
            if (x == 0) continue;
            
            int nn = (n*10) + x;
            if (nn > high) return ans;
            if (nn >= low && nn <= high) ans.push_back(nn);
            q.push(nn);
        }
        
        return ans;
    }
};