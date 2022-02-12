class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTime;
        int roomNeeded = 1;
        endTime.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < endTime.top()) {
                roomNeeded++;
            }
            else {
                endTime.pop();
            }
            endTime.push(intervals[i][1]);
        }
        
        return roomNeeded;
    }
};