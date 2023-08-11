class MyCircularDeque {
    struct Node {
        int value;
        Node* next;
        Node* prev;
        
        Node(int value, Node* next, Node* prev) {
            this->value = value;
            this->next = next;
            this->prev = prev;
        }
        
        Node() {
            this->next = this->prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    int size, cap;
    
public:
    MyCircularDeque(int k) {
        size = 0;
        cap = k;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
        if (size == cap) return false;
        
        auto temp = head->next;
        head->next = new Node(value, temp, head);
        if (temp) temp->prev = head->next;
        size++;
        
        return true;
    }
    
    bool insertLast(int value) {
        if (size == cap) return false;
        
        auto temp = tail->prev;
        tail->prev = new Node(value, tail, temp);
        if (temp) temp->next = tail->prev;
        size++;
        
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) return false;
        
        auto temp = head->next;
        head->next = temp->next;
        if (head->next) head->next->prev = head;
        delete temp;
        size--;
        
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) return false;
        
        auto temp = tail->prev;
        tail->prev = temp->prev;
        if (tail->prev) tail->prev->next = tail;
        delete temp;
        size--;
        
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return head->next->value;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return tail->prev->value;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */