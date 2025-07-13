class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // Every child gets at least one candy
        // 1. Left to Right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) 
            { //If the current child has a higher rating than the previous one
                candies[i] = candies[i - 1] + 1;
            } //this ensures: Left > Right ⇒ More candies
        }
        // 2. Right to Left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) 
            {
                candies[i] = max(candies[i], candies[i + 1] + 1); //Use max() because the left-to-right pass might have already given this child more candies, and we don't want to overwrite that.
            }
        }
        // 3. Sum all candies
        int sum = 0;
        for (int i : candies)
            sum += i;
        return sum;
    }
};
