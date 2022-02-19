class Solution {    
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> largest;
        int mn = INT_MAX;
        int ans = INT_MAX;
        
        for (int n : nums) {
            if (n&1) n *= 2;
            largest.push(n);
            mn = min(mn, n);
        }
        
        while (!largest.empty()) {
            int x = largest.top();
            largest.pop();
            
            ans = min(ans, x - mn); 
            if (x % 2 == 0) {
                mn = min(mn, x/2);
                largest.push(x/2);
            }
            else {
                break;
            }
        }
        
        return ans;
    }
};