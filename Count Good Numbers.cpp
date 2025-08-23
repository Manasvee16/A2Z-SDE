class Solution {
public:
    long long mod = 1000000007;
    long long modPow(long long base, long long exp) 
    { //compute (base^exp) % mod
        long long result = 1;
        base=base%mod; //avoid early overflow
        while (exp > 0) 
        {
            if (exp % 2 == 1)
                result = (result * base) % mod; //multiply current result by base. This handles the current bit of the exponent
            base = (base * base) % mod;
            exp=exp/2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; //Even indices are more when n is odd
        long long oddCount = n / 2;
        long long evenWays = modPow(5, evenCount); //There are 5 choices for each even-index digit → compute 5^evenCount
        long long oddWays = modPow(4, oddCount); //There are 4 choices for each odd-index digit → compute 4^oddCount
        return (evenWays * oddWays) % mod;
    }
};
//TC O(logn)
//SC O(1)

class Solution {
public:
    long long mod = 1000000007;
    // Recursive function to compute (base^exp) % mod
    long long modPow(long long base, long long exp) {
        if (exp == 0) 
            return 1;                    // base case: anything^0 = 1
        long long half = modPow(base, exp / 2);    // recursively compute base^(exp/2)
        half = (half * half) % mod;                // square it
        if (exp % 2 == 1)                          // if exponent is odd
            return (half * (base % mod)) % mod;    // multiply once more by base
        else
            return half;                           // else just return the squared result
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;         // even positions count
        long long oddCount  = n / 2;               // odd positions count
        long long evenWays = modPow(5, evenCount); // 5 choices at even positions
        long long oddWays  = modPow(4, oddCount);  // 4 choices at odd positions
        return (evenWays * oddWays) % mod;
    }
};
//TC O(logn)
//SC O(logn)
