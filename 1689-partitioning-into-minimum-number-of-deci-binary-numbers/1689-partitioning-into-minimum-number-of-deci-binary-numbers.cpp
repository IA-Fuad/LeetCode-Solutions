class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        int subtracted = 0;
        vector<bool> cnt(10);
        
        for (char c : n) {
            int x = c - '0';
            cnt[x] = true;
        }
        
        for (int x = 1; x <= 9; x++) {
            if (cnt[x]) {
                if (x < subtracted) break;
                subtracted += (x - subtracted);
            }
        }
        
        return subtracted;
    }
};

