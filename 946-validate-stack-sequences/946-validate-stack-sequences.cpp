class Solution {
//     bool poppingForFirstTime = true;
//     int getTopIndex(int k, int i) {
//         if (poppingForFirstTime) {
//             poppingForFirstTime = false;
//             return i;
//         }
//         return k;
//     }
    
//     void decreaseTopIndex(int& k, int i) {
//         if (k == -1) k = i-1;
//         else k--;
//     }
    void popStack(vector<int>& popped, int& j, stack<int>& s) {
        while (!s.empty() and j < popped.size() and s.top() == popped[j]) {
            s.pop();
            j++;
        }
    }
    
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         int i = 0, j = 0, k = -1;
//         int pus = pushed.size(), pos = popped.size();
        
//         while (i < pus and j < pos) {
//             while (pushed[getTopIndex(k, i)] == popped[j]) {
//                 decreaseTopIndex(k, i);
//                 j++;
//                 if (j == pos or k == -1) break;
//             }
//             i++;
//         }
        int i = 0, j = 0;
        int pus = pushed.size(), pos = popped.size();
        stack<int> s;
        
        while (i < pus and j < pos) {
            popStack(popped, j, s);
            s.push(pushed[i++]);
        }
        popStack(popped, j, s);
        
        if (s.empty() and j == pos and i == pus) return true;
        return false;
    }
};

/*

i = j = 1;
k = -1;

[1] i = 1
[2] i = 2
[3] i = 3
[4] i = 4 | k = i = 4 | j = 2, k = k - 1 = 3
[5] 



*/