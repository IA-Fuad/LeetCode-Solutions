class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = 0;
        string ans = "", pad = "";
        if (a.size() < b.size()) swap(a, b);
        for (int i = b.size(); i < a.size(); i++) pad += '0';
        b = pad + b;
        cout << a <<' ' << b << endl;
        for (int i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--) {
            if (a[i] == b[i]) {
                if (carry) ans += '1';
                else ans += '0';
                if (a[i] == '1') carry = true;
                else carry = false;
            }
            else {
                if (carry) ans += '0';
                else ans += '1';
            }
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};