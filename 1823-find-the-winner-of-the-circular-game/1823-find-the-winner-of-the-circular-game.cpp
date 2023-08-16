class Solution {
    int rec(int n, int k) {
        if (n == 1) return 0;
        return (rec(n-1, k) + k) % n;
    }
    
public:
    int findTheWinner(int n, int k) {
        int x = rec(n, k);
        return x + 1;
    }
};


/*

1 2 3 4 5
    1 2 3 4
        1 2 3
            1

*/