class MyCalendar {
    set<pair<int, int>> ranges;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto range = make_pair(start, end);
        auto lb = ranges.lower_bound(range);

        if (lb != ranges.end() and end > lb->first) return false;
        if (lb != ranges.begin() and start < ((--lb)->second)) return false;
        
        ranges.insert(range);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */