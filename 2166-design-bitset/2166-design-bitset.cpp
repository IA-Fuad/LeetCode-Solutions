class Bitset {
    string s = "", sc = "";
    int ones = 0;
    
public:
    Bitset(int size) {
        for (int i = 0; i < size; i++) {
            s += '0';
            sc += '1';
        }
    }
    
    void fix(int idx) {
        if (s[idx] == '0') ones++;
        s[idx] = '1';
        sc[idx] = '0';
    }
    
    void unfix(int idx) {
        if (s[idx] == '1') ones--;
        s[idx] = '0';
        sc[idx] = '1';
    }
    
    void flip() {
        swap(s, sc);
        ones = s.size() - ones;
    }
    
    bool all() {
        return ones == s.size();
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */