class MyCircularDeque {
    vector<int> dq;
    int k;
    int cnt;
    int front;
    int rear;
    
public:
    MyCircularDeque(int k) : k(k), cnt(0), front(k-1), rear(0), dq(k) {
    }
    
    bool insertFront(int value) {
        if (cnt == k) return false;
        dq[front] = value;
        front = (front - 1 + k) % k;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if (cnt == k) return false;
        dq[rear] = value;
        rear = (rear + 1) % k;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if (cnt == 0) return false;
        front = (front + 1) % k;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if (cnt == 0) return false;
        rear = (rear - 1 + k) % k;
        cnt--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : dq[(front + 1) % k];
    }
    
    int getRear() {
        return isEmpty() ? -1 : dq[(rear - 1 + k) % k];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == k;
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
 
 
 1 2 ^
 
     ^ 
 
 
 */