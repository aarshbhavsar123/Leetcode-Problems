class Solution {
public:
    int number(int x)
    {
        int count = 0;
        int z = x;
        while(z!=0)
        {
            z = z&(z-1);
            count++;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int x = start^goal;
        return number(x);
    }
};