class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        int subtracted = 0;
        
        for (char c : n) {
            int x = c - '0';
            
            if (x < subtracted) break;
            subtracted += (x - subtracted);
        }
        
        return subtracted;
    }
};

