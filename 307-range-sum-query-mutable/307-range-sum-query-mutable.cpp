class NumArray {
    vector<int> tree;
    int n;
    
    void init(int b, int e, int node, vector<int>& nums) {
        if (b > e) return;
        if (b == e) {
            tree[node] = nums[b];
            return;
        }
        
        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;
        
        init(b, mid, left, nums);
        init(mid+1, e, right, nums);
        
        tree[node] = tree[left] + tree[right];
    }
    
    void update(int b, int e, int ind, int newVal, int node) {
        if (b > e or ind < b or ind > e) return;
        if (b == e and b == ind) {
            //cout << node << endl;
            tree[node] = newVal;
            return;
        }
        
        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;
        
        update(b, mid, ind, newVal, left);
        update(mid+1, e, ind, newVal, right);
        
        tree[node] = tree[left] + tree[right];
    }
    
    int query(int b, int e, int l, int r, int node) {
        if (b > e or r < b or l > e) return 0;
        if (b >= l and e <= r) {
            return tree[node];
        }
        
        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;
        
        return query(b, mid, l, r, left) + query(mid+1, e, l, r, right);
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n * 4);
        init(0, n-1, 1, nums);
    }
    
    void update(int index, int val) {
        update(0, n-1, index, val, 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, n-1, left, right, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


/*

1 2 3 4 5

1 2 3  4 5

*/