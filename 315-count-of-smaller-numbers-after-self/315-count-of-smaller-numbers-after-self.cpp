class Solution {
    const int offset = 1e4 + 1;
    int tree[70000] = {0};
    
    void update(int b, int e, int i, int val, int x) {
        if (i > e or i < b) return;
        if (b == e and b == i) {
            tree[x] += val;
            return;
        }
        int l = x * 2;
        int r = l + 1;
        int mid = (b + e) / 2;
        
        update(b, mid, i, val, l);
        update(mid+1, e, i, val, r);
        
        tree[x] = tree[l] + tree[r];
    }
    
    int query(int b, int e, int l, int r, int x) {
        if (l > e or r < b) {
            return 0;
        }
        if (b >= l and e <= r) {
            return tree[x];
        }

        int mid = (b + e) / 2;
        return query(b, mid, l, r, x * 2) + query(mid+1, e, l, r, x * 2 + 1);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = n-1; i >= 0; i--) {
            ans[i] = query(0, offset+offset, 0, nums[i]-1+offset, 1);
            update(0, offset+offset, nums[i]+offset, 1, 1);
        }

        return ans;
    }
};

/*

1 6 2 5

1 2 6 5

*/