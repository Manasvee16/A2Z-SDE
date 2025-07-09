class Solution {
  public:
    int factorial(int n) {
        if (n==1 || n==0)
            return 1;
        int ans=1;
        while (n>1)
        {
            ans=n*ans;
            n--;
        }
        return ans;
    }
};
