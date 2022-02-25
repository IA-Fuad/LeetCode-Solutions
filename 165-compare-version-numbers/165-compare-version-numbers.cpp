class Solution {
    int getChunk(const string& v, int& i) {
        string chunk = "0";
        while (i < v.size() and v[i] != '.') {
            if (chunk.back() == '0' and v[i] == '0') {
                i++;
                continue;
            }
            chunk += v[i++];
        }
        return stoi(chunk);
    }
    
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() or j < version2.size()) {
            int v1 = getChunk(version1, i);
            int v2 = getChunk(version2, j);

            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            i++, j++;
        }

        return 0;
    }
};