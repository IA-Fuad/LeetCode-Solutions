class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), mxLen = 1, numberOfLis = 0;
        vector<int> lis(n, 1), lisCount(n+1, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        lisCount[i] = lisCount[j];
                    }
                    else if (lis[j] + 1 == lis[i]) {
                        lisCount[i] += lisCount[j];
                    }
                }
            }
            //cout << i+1 << ' ' << lis[i] << ' ' << lisCount[i] << endl;
            if (lis[i] > mxLen) {
                mxLen = lis[i];
                numberOfLis = lisCount[i];
            }
            else if (mxLen == lis[i]) {
                numberOfLis += lisCount[i];
            }
        }

        return numberOfLis;
    }
};