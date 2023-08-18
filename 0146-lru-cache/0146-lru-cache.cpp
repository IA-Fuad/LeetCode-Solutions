class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node() {}
        Node(int key, int value) {
            this->key = key;
            this->val = value;
        }
    };
    
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> keyToNode;
    
    void moveToTail(Node* node) {
       // cout << node->val << 'm' << endl;
        node->prev->next = node->next;
        node->next->prev = node->prev;
       // cout << head->next->val << endl;
        addToTail(node);
    }
    
    void deleteFromHead() {
        if (!head->next) return;
        //cout << head->next->key << 'd' << endl;
        keyToNode.erase(head->next->key);
        
        auto temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
    }
    
    void addToTail(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        
        tail->prev->next = node;
        tail->prev = node;
        
       // cout << head->next->val << ' ' << tail->prev->val << endl;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
      //  cout << key << endl;
        if (keyToNode.count(key) == 0) return -1;
        auto node = keyToNode.find(key)->second;
        moveToTail(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        //cout << key << ' ' << value << endl;
        if (keyToNode.count(key)) {
            moveToTail(keyToNode[key]);
            keyToNode[key]->val = value;
            return;
        }
        
        if (cap == 0) deleteFromHead();
        else cap--;
        
        addToTail(new Node(key, value));
        keyToNode[key] = tail->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */