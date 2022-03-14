class Solution {
public:
    string simplifyPath(string path) {
        string canonicalPath = "/", name;
        deque<string> pathNames;
        
        stringstream ss(path);
        while (getline(ss, name, '/')) {
            if (name == "." or name.size() == 0) continue;
            if (name == "..") {
                if (pathNames.size() > 0) pathNames.pop_back();
            }
            else {
                pathNames.push_back(name);
            }
        }
        
        while (pathNames.size() > 0) {
            canonicalPath += pathNames.front();
            pathNames.pop_front();
            if (pathNames.size() > 0) canonicalPath += '/';
        }
        
        return canonicalPath;
    }
};

/*



*/