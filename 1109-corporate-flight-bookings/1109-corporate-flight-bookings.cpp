class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n);
        
        for (int i = 0; i < bookings.size(); i++) {
            result[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n) result[bookings[i][1]] -= bookings[i][2];
        }
        
        for (int i = 1; i < n; i++) {
            result[i] += result[i-1];
        }
        
        return result;
    }
};

/*



*/