class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        int n = pattern.size();
        vector<int> nextIIndex(n+1);
        nextIIndex[n] = n;
        
        for (int i = n-1; i >= 0; i--) {
            if (pattern[i] == 'I') {
                nextIIndex[i] = i;
            }
            else {
                nextIIndex[i] = nextIIndex[i+1];
            }
        }
        
        int currDigit = nextIIndex[0]+1;
        int maxUsedDigit = currDigit;

        num.push_back((char)(currDigit+'0'));
        for (int i = 0; i < n; i++) {
           // cout << currDigit << ' ' << nextIIndex[i+1] << ' ' << i << ' ';
            if (pattern[i] == 'I') {
                currDigit = maxUsedDigit + (nextIIndex[i+1] - i);
            }
            else {
                currDigit--;
            }
          //  cout << currDigit << endl;
            maxUsedDigit = max(maxUsedDigit, currDigit);
            num.push_back((char)(currDigit+'0'));
        }
        
        return num;
    }
};


/*

IIIDIDDD

1 2 3 4 3 4 3 2 1

1 2 3 5 4 9 8 7 6

*/