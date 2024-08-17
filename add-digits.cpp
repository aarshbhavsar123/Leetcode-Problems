class Solution {
public:
    
    int addDigits(int num) {
        
        while(num-num%10>0)
        {
            
            int x = num;
            if(x==x%10)
            return x;
            int ans = 0;
            while(x)    
            {
                int dig = x%10;
                ans+=dig;
                x/=10;
            }
            cout<<x<<" ";
            num = ans;
        }
        return num;

    }
};