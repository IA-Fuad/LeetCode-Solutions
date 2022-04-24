class UndergroundSystem {
    unordered_map<string, pair<int, int>> stationJourneyTime;
    unordered_map<int, pair<string, int>> customerCheckIn;
    
    string getKey(string firstStation, string secondStation) {
        return firstStation + "->" + secondStation;
    }
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customerCheckIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto[checkInStation, checkInTime] = customerCheckIn[id];
        string key = getKey(checkInStation, stationName);
        
        auto it = stationJourneyTime.find(key);
        if (it != stationJourneyTime.end()) {
            it->second.first += (t - checkInTime);
            it->second.second++;
        }
        else {
            stationJourneyTime[key] = {(t - checkInTime), 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = getKey(startStation, endStation);
        auto[totalDuration, journeyCount] = stationJourneyTime[key];
        return totalDuration / (double)journeyCount;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */