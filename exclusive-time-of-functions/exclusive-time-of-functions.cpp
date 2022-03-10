class Solution {
    struct FunctionLog {
        int id;
        bool isStart;
        int time;
    };
    
    vector<FunctionLog> parseLogData(vector<string>& logs) {
        vector<FunctionLog> logData;
        for (string& log : logs) {
            replace(log.begin(), log.end(), ':', ' ');
            stringstream ss(log);

            int id, time;
            string startOrEnd;
            ss >> id;
            ss >> startOrEnd;
            ss >> time;

            logData.push_back({id, startOrEnd == "start", time});
        }

        return logData;
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<FunctionLog> logData = parseLogData(logs);
        sort(logData.begin(), logData.end(), [](FunctionLog& x, FunctionLog& y) {
           return x.time < y.time; 
        });
        
        vector<int> exclusiveTimeForEachFunction(n);
        stack<FunctionLog> callStack;
        
        for (auto log : logData) {
            if (log.isStart) {
                callStack.push(log);
            }    
            else {
                int timeSpent = 0;
                while (!callStack.empty() and callStack.top().time < 0) {
                    timeSpent += callStack.top().time;
                    callStack.pop();
                }
                int id = callStack.top().id;
                int startTime = callStack.top().time;
                callStack.pop();
                //cout << log.time - startTime + 1 << ' ' << timeSpent << endl;
                int excutionDuration = (log.time - startTime + 1) + timeSpent;
                //cout << excutionDuration << ' ';
                exclusiveTimeForEachFunction[id] += excutionDuration;
                callStack.push({-1, true, -excutionDuration+timeSpent});
            }
        }
        
        return exclusiveTimeForEachFunction;
    }
};