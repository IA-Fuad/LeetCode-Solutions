class Solution {
    int in[1002], out[1002];
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        for(int i=0; i<(int)trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];
            in[b]++;
            out[a]++;
        }
        for(int i=1; i<=N; i++){
            if(in[i] == N-1 && out[i] == 0){
                return i;
            } 
        }
        return -1;
    }
};