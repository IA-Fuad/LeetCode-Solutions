class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        
        for (auto i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int roomNeeded = 0;
        for (int s = 0, e = 0; s < intervals.size(); s++) {
            if (starts[s] >= ends[e]) {
                e++;
            }
            else {
                roomNeeded++;
            }
        }
        
        return roomNeeded;
    }
};