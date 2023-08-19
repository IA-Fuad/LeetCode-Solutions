class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int minCandy = n, i = 1;
        
        while (i < n) {
            if (ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }
            
            int up = 0, down = 0;
            
            while (i < n and ratings[i] > ratings[i-1]) {
                up++;
                i++;
                
                minCandy += up;
            }
            
            while (i < n and ratings[i] < ratings[i-1]) {
                down++;
                i++;
                
                minCandy += down;
            }
            
            minCandy -= min(up, down);
        }
        
        return minCandy;
    }
};


/*

1 5 4 3 2 1

0 1
  0 1 2 3 4

*/