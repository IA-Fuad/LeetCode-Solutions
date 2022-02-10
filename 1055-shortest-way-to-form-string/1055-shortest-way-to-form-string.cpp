class Solution {
public:
    int shortestWay(string source, string target) {
        int subSeqNeeded = 1, ss = source.size(), ts = target.size();
        vector<vector<int>> charIndices(26);
        
        for (int i = 0; i < ss; i++) {
            charIndices[source[i]-'a'].push_back(i);
        }
        
        for (int i = 0, k = -1; i < ts; i++) {
            int c = target[i] - 'a';
            if (charIndices[c].size() == 0) {
                return -1;
            }
            int foundAt = lower_bound(charIndices[c].begin(), charIndices[c].end(), k+1) - charIndices[c].begin();
            if (foundAt == charIndices[c].size()) {
                subSeqNeeded++;
                k = charIndices[c][0];
            }
            else {
                k = charIndices[c][foundAt];
            }
            //cout << foundAt << ' ';
            //cout << k << endl;
        }
        
        return subSeqNeeded;
    }
};