class Solution {
    int need;
    
    bool rec(vector<int>& ms, vector<int>& sides, int ind) {
        if (ind == ms.size()) {
            for (int k = 0; k < 4; k++) {
                if (sides[k] != sides[0]) return false;
            }
            return true;
        }
        
        bool canMakeSq = false;
        for (int k = 0; k < 4; k++) {
            if (sides[k] + ms[ind] <= need) {
                sides[k] += ms[ind];
                if (rec(ms, sides, ind + 1)) {
                    canMakeSq = true;
                    break;
                }
                sides[k] -= ms[ind];
            }
        }
        
        return canMakeSq;
    }
    
public:
    bool makesquare(vector<int>& ms) {
        int totalSum = accumulate(ms.begin(), ms.end(), 0);
        if (totalSum % 4 != 0) return false;
        
        sort(ms.rbegin(), ms.rend());
        need = totalSum / 4;
        vector<int> sides(4, 0);
        return rec(ms, sides, 0);
    }
};