class Solution {
    typedef pair<int, int> pii;
    
public:
    bool isPossible(vector<int>& nums) {
        auto comp = [](pii& x, pii& y) {
            if (x.first == y.first) return x.second > y.second;
            return x.first > y.first;
        };
        
        priority_queue<pii, vector<pii>, decltype(comp)> Q(comp);
        
        for (int i = 0; i <= nums.size(); i++) {
            int num = i < nums.size() ? nums[i] : INT_MAX;
            
            if (Q.empty()) {
                Q.push({num, 1});
            }
            else {
                auto[n, len] = Q.top();
               // cout << num << ' ' << n << ' ' << len << endl;
                
                if (num == n) {
                    Q.push({num, 1});
                }
                else {
                    while (!Q.empty()) {
                        auto[n, len] = Q.top();
                        Q.pop();

                        if (num-1 == n) {
                            Q.push({num, len+1});
                            break;
                        }
                        else if (len < 3) {
                            return false;
                        }
                    }
                    if (Q.empty()) {
                        Q.push({num, 1});
                    }
                }
            }
        }
        
        return true;
    }
};

/*



*/