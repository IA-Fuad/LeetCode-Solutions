class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> Q;
        for (int i = 1; i <= n; i++) Q.push(i);
        
        int steps = 1;
        while (Q.size() > 1) {
            int curr = Q.front();
            Q.pop();
            
            if (steps == k) {
                steps = 0;
            } 
            else {
                Q.push(curr);
            }
            steps++;
        }
        
        return Q.front();
    }
};

/*

*/