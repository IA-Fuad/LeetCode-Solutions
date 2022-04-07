class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for (int s : stones) {
            Q.push(s);
        }
        
        while (!Q.empty() and Q.size() > 1) {
            int y = Q.top();
            Q.pop();
            int x = Q.top();
            Q.pop();
            
            if (x != y) {
                Q.push(y - x);
            }
        }
        
        return Q.empty() ? 0 : Q.top();
    }
};