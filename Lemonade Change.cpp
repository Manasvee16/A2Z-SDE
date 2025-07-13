class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0, twenty=0;
        for (int i:bills)
        {
            if (i==5)
                five++;
            else if (i==10)
            {
                if (five==0)
                {
                    return false;
                }
                ten++;
                five--;
            }
            else if (i==20)
            {
                if (ten>=1 && five>=1)
                {
                    ten--;
                    five--;
                }
                else if (five>=3)
                {
                    five=five-3;
                }
                else
                    return false;
                twenty++;
            }
        }
        return true;
    }
};
