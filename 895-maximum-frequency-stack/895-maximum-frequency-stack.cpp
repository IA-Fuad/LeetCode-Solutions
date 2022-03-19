class FreqStack {
public:
    FreqStack() {
        head = new Node(-1, 0);
        tail = new Node(-1, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int val) {
        valueScores[val]++;
        auto newNode = new Node(val, valueScores[val]);
        insertInTheStack(newNode);
    }
    
    int pop() {
        int top = popLastNode();
        valueScores[top]--;
        return top;
    }

private:
    struct Node {
        int value;
        int score;
        Node* next = nullptr;
        Node* prev = nullptr;
        
        Node(int value, int score) {
            this->value = value;
            this->score = score;
        }
    };
    
    Node* head;
    Node* tail;
    
    unordered_map<int, int> valueScores;
    unordered_map<int, Node*> scoreToNode;
    
    void insertInTheStack(Node* node) {
        auto it = scoreToNode.find(node->score);
        if (it == scoreToNode.end()) {
            insertAtTaile(node);
        }
        else {
            insertAfterNode(node, it->second);
        }
        scoreToNode[node->score] = node;
    }
    
    void insertAtTaile(Node* newNode) {
        insertAfterNode(newNode, tail->prev);
    }
    
    void insertAfterNode(Node* newNode, Node* node) {
        auto currentNext = node->next;
        node->next = newNode;
        currentNext->prev = newNode;
        newNode->prev = node;
        newNode->next = currentNext;
    }
    
    int popLastNode() {
        updateScoreToNode(tail->prev);
        
        auto topNode = tail->prev;
        topNode->prev->next = tail;
        tail->prev = topNode->prev;
        int topVal = topNode->value;
        
        delete topNode;
        return topVal;
    }
    
    void updateScoreToNode(Node* node) {
        if (node->score != node->prev->score) {
            scoreToNode.erase(node->score);
        }
        else {
            scoreToNode[node->score] = node->prev;
        }
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

/*

5(1)<->7(1)<->4(1)<->5(2)<->7(2)<->5(3)

map[1] = address of last 4
map[3] = address of last 5

*/