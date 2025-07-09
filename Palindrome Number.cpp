class Solution 
{
public:
    bool isPalindrome(long long int x) 
    {
        if (x<0)
            return false;
        else
        {
            long long int z=x;
            long long int y=0;
            while (x)
            {
                y=y*10+x%10; //create the new number
                x=x/10;
            }
            if (z==y) //if new number is same as original
                return true;
            else
                return false;
        }
    }
};
