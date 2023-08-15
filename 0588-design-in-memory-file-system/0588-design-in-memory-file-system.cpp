class FileSystem {
    struct Node {
        bool isFile = false;
        unordered_map<string, Node*> next;
        vector<string> names;
        string content;
    }*root;
    
    Node* createDir(string path, bool isFile = false) {
        auto curr = root;
        stringstream ss(path);
        string d;
        
        while (getline(ss, d, '/')) {
            if (d == "") continue;
            if (!curr->next.count(d)) {
                curr->names.push_back(d);
                curr->next[d] = new Node();
            }
            curr = curr->next[d];
        }
        curr->isFile = isFile;
        if (isFile) curr->names.push_back(d);
        return curr;
    }
    
    Node* getPathContents(string path) {
        auto curr = root;
        Node* prev;
        stringstream ss(path);
        string d;
        
        while (getline(ss, d, '/')) {
            if (d == "") continue;
            prev = curr;
            curr = curr->next[d];
        }
        return curr;
    }
    
public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        auto node = getPathContents(path);
        sort(node->names.begin(), node->names.end());
        return node->names;
    }
    
    void mkdir(string path) {
        createDir(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto curr = createDir(filePath, true);
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto node = getPathContents(filePath);
        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */