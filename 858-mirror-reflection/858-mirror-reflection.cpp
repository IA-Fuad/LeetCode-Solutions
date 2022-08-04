class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (q == 0) return q;
        
        int height = q;
        
        while (height < p or height % p != 0) {
            height += q;
        }
        
        int upFlip = height / p;
        int rightFlip = height / q;
        
        //cout << upFlip << ' ' << rightFlip << endl;
        
        int hitCorner = (upFlip % 2 == 0) ? 0 : 1;
        hitCorner = (rightFlip % 2 != 0) ? hitCorner : 2;
        
        return hitCorner;
    }
};