class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        
        for (int i = 0, j = people.size()-1; i <= j;) {
            if (people[i] + people[j] <= limit) {
                i++, j--;
            }
            else {
                j--;
            }
            boats++;
        }
        
        return boats;
    }
};

/*

1 2 3 5


*/