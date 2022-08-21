class Solution {
    bool match(string& target, string& stamp, vector<int>& order) {
        int ss = stamp.size(), ts = target.size();
        bool anyMatched = false;

        for (int i = 0; i+ss <= ts; i++) {
            bool matched = true, allMatched = true;
            
            for (int j = i, k = 0; k < ss; j++, k++) {
                if (target[j] == '?') continue;
                allMatched = false;
                
                if (target[j] != stamp[k]) {
                    matched = false;
                    break;
                }
            } 
            if (matched and !allMatched) {
                //cout << i << ' ';
                anyMatched = (anyMatched | matched);
                for (int j = i, k = 0; k < ss; k++) {
                    target[j++] = '?';
                }
                order.push_back(i);
            }
        }
        return anyMatched;
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> order;
        int ss = stamp.size();
        bool left = true;

        while (match(target, stamp, order)); //cout << target << ' ' << order.size() << ' ';
        
        bool allMatched = true;
        for (char c : target) {
            if (c != '?') {
                allMatched = false;
                break;
            }
        }
        
        if (!allMatched) return {};
        
        reverse(order.begin(), order.end());
        
        return order;
    }
};