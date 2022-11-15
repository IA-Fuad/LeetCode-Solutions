class MedianFinder {
    priority_queue<int> hi;
    priority_queue<int, vector<int>, greater<int>> lo;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        hi.push(num);
        lo.push(hi.top());
        hi.pop();
        
        if (lo.size() > hi.size()) {
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        return lo.size() == hi.size() ? (double)(lo.top() + hi.top())/2.0 : hi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */