/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> allSchedule, freeTime;
        for (auto s : schedule) {
            for (auto i : s) {
                allSchedule.push_back(i);
            }
        }
        sort(allSchedule.begin(), allSchedule.end(), [](auto& x, auto& y) {
           if (x.start == y.start) return x.end < y.end;
            return x.start < y.start;
        });

        int last = allSchedule[0].end;
        for (int i = 1; i < allSchedule.size(); i++) {
            if (allSchedule[i].start - last > 0) {
                freeTime.push_back(Interval(last, allSchedule[i].start));
            }
            last = max(last, allSchedule[i].end);
        }
        
        return freeTime;
    }
};