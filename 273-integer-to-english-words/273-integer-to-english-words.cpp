class Solution {
    vector<int> nums = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<string> words = {"Billion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};
        
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string word;
        
        for (int i = 0; i < nums.size(); i++) {
            //cout << num << ' ' << nums[i] << endl;
            if (num >= nums[i]) {
                if (nums[i] < 100) {
                    string temp;
                    if (nums[i] == num) {
                        temp = words[i];
                    }
                    else {
                        temp = words[i] + " " + numberToWords(num % nums[i]);
                    }
                    if (word.size() > 0) word += (' ' + temp);
                    else word = temp;
                    break;
                }
                
                int x = num / nums[i];
                num %= nums[i];

                string temp = numberToWords(x) + " " + words[i];
                if (word.size() > 0) word += (' ' + temp);
                else word = temp;
            }
        }
        
        return word;
    }
};

/*

1000000000

*/