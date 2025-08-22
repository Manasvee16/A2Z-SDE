class Solution {
  public:
    bool armstrongNumber(int n) {
        int temp=n, ans=0;
        while (n>0)
        {
            ans+=pow((n%10), 3);
            n=n/10;
        }
        return (temp==ans);
    }
};
