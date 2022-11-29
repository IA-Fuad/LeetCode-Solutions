public class RandomizedSet {
    private List<int> _nums;
    private Dictionary<int, int> _numsIndex;
    
    public RandomizedSet() {
        _nums = new List<int>();
        _numsIndex = new Dictionary<int, int>();
    }
    
    public bool Insert(int val) {
        if (_numsIndex.ContainsKey(val)) {
            return false;
        }
        _nums.Add(val);
        _numsIndex.Add(val, _nums.Count-1);
        return true;
    }
    
    public bool Remove(int val) {
        if (!_numsIndex.ContainsKey(val)) {
            return false;
        }
        int valIndex = _numsIndex[val];
        int lastElement = _nums[_nums.Count-1];
        int lastElementIndex = _numsIndex[lastElement];
        
        (_nums[_nums.Count-1], _nums[valIndex]) = (_nums[valIndex], _nums[_nums.Count-1]);
        
        _numsIndex[lastElement] = valIndex;
        _numsIndex.Remove(val);
        _nums.RemoveAt(_nums.Count-1);
        return true;
    }
    
    public int GetRandom() {
        var random = new Random();
        return _nums[random.Next(_nums.Count)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */