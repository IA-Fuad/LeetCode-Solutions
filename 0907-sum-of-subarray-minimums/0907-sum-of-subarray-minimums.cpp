class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        
        stack<int> nums;
        int n = arr.size();
        nums.push(-1);
        nums.push(0);
        
        int64_t sum = 0;
        
        for (int i = 1; i <= n; i++) {
            while (nums.top() != -1 and (i == n or arr[nums.top()] >= arr[i])) {
                int mid = nums.top();
                nums.pop();

                int64_t cnt = (mid-nums.top()) * (i-mid) % mod;
                sum += (arr[mid] * cnt) % mod;
                sum %= mod;
                //cout << arr[mid] << ' ' << sum << endl;
            }
            nums.push(i);
        }
        
        return sum;
    }
};