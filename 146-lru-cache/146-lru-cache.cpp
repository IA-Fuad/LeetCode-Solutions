struct Data {
    int key;
    int value;
    Data* prev;
    Data* next;
    
    Data() {
        this->key = this->value = -1;
        this->prev = this->next = nullptr;
    }
    
    Data(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = this->next = nullptr;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, Data*> keyToData;
    Data* head;
    Data* tail;
    
    void moveToTail(Data* data) {
        data->next->prev = data->prev;
        data->prev->next = data->next;
        addToTail(data);
    }
    
    void addToTail(int key, int value) {
        addToTail(new Data(key, value));
    }
    
    void addToTail(Data* data) {
        data->prev = tail->prev;
        data->next = tail;
        data->prev->next = data;
        tail->prev = data;
    }
    
    void deleteFromHead() {
        auto tempHead = head->next;
        tempHead->next->prev = head;
        head->next = tempHead->next;
        keyToData.erase(tempHead->key);
        delete tempHead;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Data();
        this->tail = new Data();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    
    int get(int key) {
        auto it = keyToData.find(key);
        if (it != keyToData.end()) {
            moveToTail(it->second);
            return it->second->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            auto newData = new Data(key, value);
            addToTail(newData);
            keyToData[key] = newData;
            
            if (capacity > 0) {
                capacity--;
            }
            else {
                deleteFromHead();
            }
        }
        else {
            keyToData[key]->value = value;
            moveToTail(keyToData[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */