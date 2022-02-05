class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        
        int N = nums.size();
        int n = N/3;
        int64_t sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < n; i++) {
            left.push(nums[i]);
            sum1 += nums[i];
        }
        for (int i = n*2; i < N; i++) {
            right.push(nums[i]);
            sum2 += nums[i];
        }
        
        unordered_map<int, int64_t> diff;
        
        diff[-1] = sum1;
        for (int i = 0, k = n; i < n; i++, k++) {
            if (left.top() > nums[k]) {
                sum1 -= left.top();
                sum1 += nums[k];
                left.pop();
                left.push(nums[k]);
            }
            diff[i] = sum1;
        }
        
        int64_t mn = diff[n-1] - sum2;
        //cout << diff[n-1] << ' ' << sum2 << endl;
        for (int i = n-2, k = n+n-1; i >= -1; i--, k--) {
            if (right.top() < nums[k]) {
                sum2 -= right.top();
                sum2 += nums[k];
                right.pop();
                right.push(nums[k]);
            }
            //cout << diff[i] << ' ' << sum2 << endl;
            mn = min(mn, diff[i] - sum2);
        }
        
        return mn;
    }
};