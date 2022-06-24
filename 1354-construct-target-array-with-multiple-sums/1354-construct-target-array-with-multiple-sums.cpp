class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        
        priority_queue<int> Q;
        int64_t currentSum = 0, i = 0;
        
        for (int t : target) {
            Q.push(t);
            currentSum += t;
        }
        
        while (Q.top() > 1) {
            int top = Q.top();
            Q.pop();
            
            int rest = currentSum - top;
            if (rest == 1) return true;
            
            int needed = top % rest;
          //  cout << needed << ' ' << currentSum << ' ' << top << endl;
            if (needed == 0 or needed == top) {
                return false;
            }
            
            Q.push(needed);
            currentSum = currentSum - top + needed;
        }
        
        return Q.top() == 1;
    }
};


/*

9
5
3

5
3
1

*/