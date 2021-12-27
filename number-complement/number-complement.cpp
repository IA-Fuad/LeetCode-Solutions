class Solution {
public:
    int findComplement(int num) {
        int64_t x = log2(num)+1;
        x = ((int64_t)1<<x)-1;
        return num^x;
    }
};