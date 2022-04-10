class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> Q;
        for (const string& op : ops) {
            if (op[0] == 'C') Q.pop_back();
            else if (op[0] == 'D') {
                Q.push_back(Q.back() * 2);
            }
            else if (op[0] == '+') {
                Q.push_back(Q.back() + Q[Q.size()-2]);
            }
            else {
                Q.push_back(stoi(op));
            }
        }
        
        int sum = 0;
        for (int n : Q) sum += n;
        
        return sum;
    }
};