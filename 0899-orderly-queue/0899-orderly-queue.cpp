class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        char smallest = s[0];
        int smallestInd = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == smallest) {
                for (int a = smallestInd, b = i; a < i; a++, b++) {
                    if (b == s.size()) {
                        b = 0;
                    }
                    if (b == smallestInd or s[b] > s[a]) {
                        break;
                    }
                    if (s[b] < s[a]) {
                        smallest = s[i];
                        smallestInd = i;
                        break;
                    }
                }
            }
            else if (s[i] < smallest) {
                smallest = s[i];
                smallestInd = i;
            }
        }
        //cout << smallestInd << ' ';
        if (smallestInd > 0) {
            s = s.substr(smallestInd, s.size()-smallestInd) + s.substr(0, smallestInd);
        }
        
        return s;
    }
};

/*

xvcbqweraslkfjf

xcba

cbax
baxc
axcb


baaca
aacab
aaabc

*/