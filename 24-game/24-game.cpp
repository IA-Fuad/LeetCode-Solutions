class Solution {
    bool found = false;
    void rec(vector<double>& cards) {
        if (cards.size() == 1) {
            if (abs(cards[0] - 24.0) < 0.001) {
                found = true;
            }
            return;
        }
        for (int i = 0; i < cards.size() and !found; i++) {
            for (int j = i+1; j < cards.size(); j++) {
                double a = cards[i];
                double b = cards[j];
                //cout << cards[i] << ' ' << cards[j] << endl;
                cards.erase(cards.begin() + i);
                cards.erase(cards.begin() + j - 1);
                
                vector<double> ans = {a+b, a-b, b-a, a*b};
                if (abs(b) > 0.001) ans.push_back(a/b);
                if (abs(a) > 0.001) ans.push_back(b/a);
                
                for (double x : ans) {
                    cards.push_back(x);
                    rec(cards);
                    cards.pop_back();
                }
                
                cards.insert(cards.begin() + i, a);
                cards.insert(cards.begin() + j, b);
                //cout << cards[i] << ' ' << cards[j] << endl << endl;
            }
        }
    }
    
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> ans;
        for (int i = 0; i < cards.size(); i++) ans.push_back(cards[i]);
        rec(ans);
        return found;
    }
};