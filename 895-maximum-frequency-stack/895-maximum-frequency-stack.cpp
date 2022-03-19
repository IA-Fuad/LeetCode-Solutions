class FreqStack {
    unordered_map<int, stack<int>> freqStack;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqStack[freq[val]].push(val);
    }
    
    int pop() {
        int val = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        if (freqStack[maxFreq].empty()) {
            maxFreq--;
        }
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */