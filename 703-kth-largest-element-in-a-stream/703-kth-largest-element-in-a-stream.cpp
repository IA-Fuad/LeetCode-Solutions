class KthLargest {
    priority_queue<int, vector<int>, greater<int>> Q;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) add(n);
    }
    
    int add(int val) {
        Q.push(val);
        if (Q.size() > k) Q.pop();
        
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */