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
    
    void merge(vector<int>& cnt, vector<pair<int, int>>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge(cnt, nums, l, mid);
        merge(cnt, nums, mid+1, r);
        
        vector<pair<int, int>> temp;
        int fromRight = 0, i, j;
        for (i = l, j = mid+1; i <= mid and j <= r; ) {
            if (nums[i] <= nums[j]) {
                cnt[nums[i].second] += fromRight;
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
                fromRight++;
            }
        }
        while (i <= mid) {
            cnt[nums[i].second] += fromRight;
            temp.push_back(nums[i++]);
        }
        while (j <= r) {
            temp.push_back(nums[j++]);
        }
        
        for (int i = l, k = 0; i <= r; i++) nums[i] = temp[k++];
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

//         for (int i = n-1; i >= 0; i--) {
//             ans[i] = query(0, offset+offset, 0, nums[i]-1+offset, 1);
//             update(0, offset+offset, nums[i]+offset, 1, 1);
//         }
        
        vector<pair<int, int>> ni;
        for (int i = 0; i < n; i++) {
            ni.push_back({nums[i], i});
        }
        merge(ans, ni, 0, n-1);

        return ans;
    }
};

/*

1 6 2 5

1 2 6 5

*/