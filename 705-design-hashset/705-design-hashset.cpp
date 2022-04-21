class MyHashSet {

    struct Node {
        int key;
        Node* left;
        Node* right;
        Node* lastNode;
        
        Node(int key) {
            this->key = key;
            left = right = nullptr;
            lastNode = this;
        }
    };

    vector<Node*> hashSet;
    const int size = 1000;
    
    Node* getNodeByKey(Node* root, int key) {
        //cout << root->key << ' ' << key << endl;
        if (!root or root->key == key) return root;
        return key > root->key ? getNodeByKey(root->right, key) : getNodeByKey(root->left, key);
    }
    
    int getInorderSuccessor(Node* root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root->key;
    }
    
    Node* deleteNodeFromBST(Node* curr, int key) {
        if (!curr) {
            return curr;
        }
        if (curr->key > key) {
            curr->left = deleteNodeFromBST(curr->left, key);
        }
        else if (curr->key < key) {
            curr->right = deleteNodeFromBST(curr->right, key);
        }
        else {
            if (!curr->left and !curr->right) {
                delete curr;
                return nullptr;
            }
            if (!curr->right) {
                auto temp = curr->left;
                delete curr;
                return temp;
            }
            else if (!curr->left) {
                auto temp = curr->right;
                delete curr;
                return temp;
            }
            
            curr->key = getInorderSuccessor(curr);
            curr->right = deleteNodeFromBST(curr->right, curr->key);
        }
        return curr;
    }
    
public:
    MyHashSet() {
        hashSet.resize(size, new Node(-1));
    }
    
    void add(int key) {
        //cout << "add " << key << endl;
        if (contains(key)) {
            return;
        }
        
        int index = key % size;
        auto newNode = new Node(key);
        auto root = hashSet[index];
        
        while (root) {
            if (key > root->key) {
                if (!root->right) {
                    root->right = newNode;
                    break;
                }
                else {
                    root = root->right;
                }
            }
            else {
                if (!root->left) {
                    root->left = newNode;
                    break;
                }
                else {
                    root = root->left;
                }
            }
        }
    }
    
    void remove(int key) {
       // cout << "remove " << key << endl;
        auto root = hashSet[key % size];
        deleteNodeFromBST(root, key);
    }
    
    bool contains(int key) {
        //cout << "contains " << key << endl;
        if (getNodeByKey(hashSet[key%size], key)) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */