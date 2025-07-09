class Solution {
  public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) //if a divisor exists
                return false;
        }
        return true;
    }
};
