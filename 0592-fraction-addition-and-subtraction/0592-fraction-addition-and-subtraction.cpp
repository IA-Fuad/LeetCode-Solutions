class Solution {
public:
    string fractionAddition(string expression) {
        int A = 0, B = 1, a, b;
        char c;
        stringstream ss(expression);
        
        while (ss >> a >> c >> b) {
            A = (A * b) + (a * B);
            B *= b;
            //cout << a << ' ' << c << ' ' << b << endl;
            int gcd = abs(__gcd(A, B));
            
            A /= gcd;
            B /= gcd;
        }
        
        return to_string(A) + "/" + to_string(B);
    }
    
    int _gcd(int A, int B) {
        if (A == 0) return B;
        return _gcd(B, A % B);
    }
};