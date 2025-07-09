class Solution {
  public:
    int countDigits(int n) {
        if (n>=0 && n<=9)
            return 1;
        int count=1;
        while (n>9)
        {
            n=n/10;
            count++;
        }
        return count;
    }
};
