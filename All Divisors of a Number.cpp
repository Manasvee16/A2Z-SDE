class Solution {
  public:
    void print_divisors(int n) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) { //check till square root
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) { //distinct divisor
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        for (int d : divisors) {
            cout << d << " ";
        }
    }
};
