class StockSpanner {
    stack<pair<int, int>> stocks;
    int index;
    
public:
    StockSpanner() {
        stocks.push({INT_MAX, -1});
        index = 0;
    }
    
    int next(int price) {
        while (price >= stocks.top().first) {
            stocks.pop();
        }
        int span = index - stocks.top().second;
        stocks.push({price, index});
        index++;
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 
 100,0
 85,6
 
 */