class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b)->bool {
            string num1 = to_string(a);
            string num2 = to_string(b);
            
            if (num1+num2 > num2+num1) return true;
            return false;
        });
        
        string largestNum;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 and largestNum.size() == 0 and i < nums.size()-1) continue;
            largestNum += to_string(nums[i]);
        }
        return largestNum;
    }
};

/*

"343233432"
"343234323"

34323


*/