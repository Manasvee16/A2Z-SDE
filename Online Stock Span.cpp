class StockSpanner {
    // Monotonic stack storing pairs: {price, span}
    // Invariant: prices are stored in strictly decreasing order from bottom to top.
    stack<pair<int, int>> stocks;
public:
    StockSpanner() {
        // No initialization needed; stack starts empty.
    }
    int next(int price) {
        int count = 1; // At least today's day counts as span = 1
        // While there are previous days with price <= today's price, they are part of today's span; merge their spans into 'count'. Pop them because today's price dominates them for future queries.
        while (!stocks.empty() && stocks.top().first <= price) {
            count += stocks.top().second; // add the span of the popped price
            stocks.pop(); // remove it (compressed/merged)
        }
        stocks.push({price, count}); // Push today's {price, accumulated span} onto the stack. Now the stack remains strictly decreasing by price.
        return stocks.top().second; // The answer for this query is the span we just computed.
    }
};
//TC O(1)
//SC O(N)
