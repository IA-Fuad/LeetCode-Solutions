class Vector2D {
    vector<vector<int>>* twoDVec;
    int i, j;
    
    void moveToNext() {
        while (i < twoDVec->size() and j >= twoDVec->at(i).size()) {
            i++;
            j = 0;
        }
    }
    
public:
    Vector2D(vector<vector<int>>& vec) {
        twoDVec = &vec;
        i = j = 0;
    }
    
    int next() {
        moveToNext();
        
        int currValue = twoDVec->at(i).at(j);
        j++;
        
        return currValue;
    }
    
    bool hasNext() {
        moveToNext();
        return i < twoDVec->size() and j < twoDVec->at(i).size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */