class Solution {
    int getMaxConsecutiveAnswers(const string& answerKey, int k, char flip) {
        int currMax = 0, curr = 0;
        for (int i = 0, j = 0; i < answerKey.size(); i++) {
            if (answerKey[i] == flip) {
                while (k <= 0 and j < i) {
                    k += (answerKey[j++] == flip ? 1 : 0);
                }
                k--;
            }
            currMax = max(currMax, i - j + 1);
        }
        return currMax;
    }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getMaxConsecutiveAnswers(answerKey, k, 'T'), getMaxConsecutiveAnswers(answerKey, k, 'F'));
    }
};