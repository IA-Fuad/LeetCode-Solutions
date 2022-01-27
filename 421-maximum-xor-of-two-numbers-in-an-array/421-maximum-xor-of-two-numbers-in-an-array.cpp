class Solution {
    struct Node {
        unordered_map<bool, Node*> next; 
    } *root;
    
    int insertNumber(vector<bool> num) {
        Node* curr = root;
        for (bool b : num) {
            //cout << b << ' ';
            if (curr->next.find(b) == curr->next.end()) curr->next[b] = new Node();
            curr = curr->next[b];
        }
        //cout << endl;
        int currXor = 0;
        curr = root;
        
        for (bool b : num) {
            bool toggledBit = !b;
            if (curr->next.find(toggledBit) != curr->next.end()) {
                currXor = (currXor << 1) | 1;
                curr = curr->next[toggledBit];
            }
            else {
                currXor = (currXor << 1);
                curr = curr->next[b];
            }
            //currXor = currXor << 1;
        }
        
        return currXor;
    }
    
    int getMaxBitLen(vector<int>& nums) {
        int mxBitLen = 0;
        for (int n : nums) {
            int i = 1;
            while (n>>i) i++;
            mxBitLen = max(mxBitLen, i);
        }
        return mxBitLen;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int mxBitLen = getMaxBitLen(nums);
        root = new Node();
        
        vector<vector<bool>> binNums;
        
        for (int n : nums) {
            vector<bool> num;
            for (int i = 0; i < mxBitLen; i++) {
                num.push_back((n >> i) & 1);
            }
            reverse(num.begin(), num.end());
            binNums.push_back(num);
        }
        
        int mxXor = 0;
        for (int i = 0; i < binNums.size(); i++) {
            mxXor = max(mxXor, insertNumber(binNums[i]));
        }
        
        return mxXor;
    }
};