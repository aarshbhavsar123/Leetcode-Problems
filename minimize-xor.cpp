class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int maxi = 0;
        int count2 = __builtin_popcount(num2);
        for(int i = 31;i>=0 && count2>0;i--)
        {
            if((num1>>i)&1)
            {
                maxi|=(1<<i);
                count2--;
            }
        }
        for(int i = 0;i<32 && count2>0;i++)
        {
            if(((maxi>>i)&1)==0)
            {
                maxi|=(1<<i);
                count2--;
            }
        }
        return maxi;
    }
};