class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        if (arr[0] >= arr[1]) return false;
        
        bool shouldDecrease = false;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i-1] || (shouldDecrease && arr[i] > arr[i-1])) return false;
            if (arr[i] < arr[i-1]) shouldDecrease = true;
        }
        
        return shouldDecrease;
    }
};