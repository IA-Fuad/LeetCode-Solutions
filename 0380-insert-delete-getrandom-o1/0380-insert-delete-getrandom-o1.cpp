class RandomizedSet {
    unordered_map<int, int> numInd;
    vector<int> nums;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numInd.count(val)) return false;
        nums.push_back(val);
        numInd[val] = (int)(nums.size() - 1);
        return true;
    }
    
    bool remove(int val) {
        if (!numInd.count(val)) return false;

        auto it = numInd.find(val);
        numInd[nums[nums.size() - 1]] = it->second;
        swap(nums[it->second], nums[nums.size() - 1]);
        numInd.erase(it);
        nums.pop_back();
        
        return true;
    }
    
    int getRandom() {
        //cout << nums[0] << ' ';
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */