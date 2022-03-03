struct Data {
    int key;
    int value;
    Data* prev;
    Data* next;
    
    Data(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = this->next = nullptr;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, Data*> keyToData;
    Data* head = nullptr;
    Data* tail = nullptr;
    
    void moveToTail(int key) {
        auto data = keyToData[key];
        if (data == tail) {
            return;
        }
        if (data == head) {
            head = head->next;
        }
        if (data->prev) {
            data->prev->next = data->next;
        }
        if (data->next) {
            data->next->prev = data->prev;
        }
        addToTail(data);
        
        if (!head) head = tail;
    }
    
    void addToTail(int key, int value) {
        addToTail(new Data(key, value));
    }
    
    void addToTail(Data* data) {
        tail->next = data;
        data->prev = tail;
        data->next = nullptr;
        tail = data;
    }
    
    void deleteFromHead() {
        if (head) {
            auto tempHead = head;
            if (head->next) {
                head->next->prev = nullptr;
                head = head->next;
            }
            else {
                head = tail = nullptr;
            }

            keyToData[tempHead->key] = nullptr;
            delete tempHead;
        }
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = keyToData.find(key);
        if (it != keyToData.end() and it->second != nullptr) {
            moveToTail(key);
            return it->second->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
           if (!head) {
                head = new Data(key, value);
                tail = head;
            }
            else {
                addToTail(key, value);
            }
            keyToData[key] = tail;
            
            if (capacity > 0) {
                capacity--;
            }
            else {
                deleteFromHead();
            }
        }
        else {
            keyToData[key]->value = value;
            moveToTail(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */