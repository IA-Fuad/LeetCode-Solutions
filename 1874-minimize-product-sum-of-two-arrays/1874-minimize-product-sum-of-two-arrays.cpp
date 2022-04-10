class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> Q1;
        priority_queue<int, vector<int>, greater<int>> Q2;
        
        for (int n : nums1) Q1.push(n);
        for (int n : nums2) Q2.push(n);
        
        int sum = 0;
        
        while (!Q1.empty()) {
            sum += (Q1.top() * Q2.top());
            Q1.pop();
            Q2.pop();
        }
        
        return sum;
    }
};