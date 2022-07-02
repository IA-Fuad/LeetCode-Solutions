class Solution {
    const int mod = 1e9 + 7;
    
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int64_t width = max(w - vc[vc.size()-1], vc[0]);
        for (int i = 1; i < vc.size(); i++) {
            width = max(width, (int64_t)vc[i] - vc[i-1]);
        }
        
        int64_t height = max(h - hc[hc.size()-1], hc[0]);
        for (int i = 1; i < hc.size(); i++) {
            height = max(height, (int64_t)hc[i] - hc[i-1]);
        }
        //cout << height << ' ' << width << endl;
        return ((height%mod) * (width%mod)) % mod;
    }
};