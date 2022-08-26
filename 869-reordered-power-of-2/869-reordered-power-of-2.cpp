class Solution {
    string getKey(int n) {
        vector<int> digitCount(10);
        
        while (n > 0) {
            digitCount[n%10]++;
            n /= 10;
        }
        
        string key;
        for (int d = 0; d < 10; d++) {
            key.push_back(digitCount[d]+'0');
        }
        //cout << key << ' ';
        return key;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> powers;
        for (int p = 0; (1LL << p) < INT_MAX; p++) {
            powers.insert(getKey(1 << p));
        }
        
        if (powers.find(getKey(n)) != powers.end()) return true;
        return false;
    }
};