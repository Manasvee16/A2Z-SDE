class Solution 
{
public:
    int reverse(int x) 
    {
        int y=0;
        while(x)
        {
            if (y>INT_MAX/10 || y<INT_MIN/10) //divided to prevent overflow
               return 0;
            else
            {
                y=10*y+x%10; //form the new number by shifting digits to left
                x=x/10;
            }
        }
        return y;
    }
};
