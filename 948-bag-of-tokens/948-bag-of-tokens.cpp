class Solution {
    int getScore(vector<int>& tokens, int currPower, int i, int j) {
        int currScore = 0;

        for (int k = i+1; k < j; k++) {
            if (currPower >= tokens[k]) {
                currPower -= tokens[k];
                currScore++;
            }
            else {
                break;
            }
        }
        
        return currScore;
    }
    
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.size() == 0) return 0;
        
        sort(tokens.begin(), tokens.end());
        int ts = tokens.size(), score = getScore(tokens, power, -1, ts);
        
        for (int i = 0, j = ts-1; i < j; i++, j--) {
            if (tokens[i] > power) {
                break;
            }
            power = (power - tokens[i] + tokens[j]);

            score = max(score, getScore(tokens, power, i, j));
            
           // cout << power << ' ' << score << endl;
        }
        
        return score;
    }
};