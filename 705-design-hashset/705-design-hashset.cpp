class MyHashSet {

    struct Node {
        int key;
        Node* next;
        Node* prev;
        Node* lastNode;
        
        Node(int key) {
            this->key = key;
            next = prev = nullptr;
            lastNode = this;
        }
    };

    vector<Node*> hashSet;
    const int size = 1000;
    
    Node* getNodeByKey(int key) {
        int index = key % size;
        
        auto curr = hashSet[index];
        while (curr and curr->key != key) {
            curr = curr->next;
        }
        return curr;
    }
    
public:
    MyHashSet() {
        hashSet.resize(size, new Node(-1));
    }
    
    void add(int key) {
        if (getNodeByKey(key)) {
            return;
        }
        int index = key % size;
        auto newNode = new Node(key);
        hashSet[index]->lastNode->next = newNode;
        newNode->prev = hashSet[index]->lastNode;
        hashSet[index]->lastNode = newNode;
    }
    
    void remove(int key) {
        auto node = getNodeByKey(key);
        if (node) {
            node->prev->next = node->next;
            if (node->next) {
                node->next->prev = node->prev;
            }
            else {
                hashSet[key%size]->lastNode = node->prev;
            }
            delete node;
        }
    }
    
    bool contains(int key) {
        if (getNodeByKey(key)) return true;
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