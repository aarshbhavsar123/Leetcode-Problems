class Solution {
public:
    bool isdiv7(string num)  
    {
        int n = num.length(), gSum=0;
        if (n == 0)
            return 1;
        if (n % 3 == 1) {
            num="00" + num;
            n += 2;
        }
        else if (n % 3 == 2) {
            num= "0" + num;
            n++;
        }

        int i, GSum = 0, p = 1;
        for (i = n - 1; i >= 0; i--) {

            int group = 0;
            group += num[i--] - '0';
            group += (num[i--] - '0') * 10;
            group += (num[i] - '0') * 100;

            gSum = gSum + group * p;
            p *= (-1);
        }

        return (gSum % 7 == 0);
    }
    string largestPalindrome(int n, int k) {
        string ans(n,'9');
        if(k==1||k==3||k==9)
        {
            return ans;
        }
        else if(k==2)
        {
            if(n==1)
            return "8";
            else if(n==2)
            return "88";
            else{
                ans[0] = '8';
                ans[ans.size()-1] = '8';
                return ans;
            }
        }
        else if(k==4)
        {
            if(n==1)
            return "8";
            else if(n==2)
            return "88";
            else if(n==3)
            return "888";
            else 
            {
                ans[0] = '8';
                ans[1] = '8';
                ans[ans.size()-1] = '8';
                ans[ans.size()-2] = '8';
                return ans;
            }
        }
        else if(k==5)
        {
            if(n==1)
            return "5";
            else if(n==2)
            return "55";
            else{
                ans[0] = '5';
                ans[ans.size()-1] = '5';
                return ans;
            }
        }
        else if(k==8)
        {
            if(n==1)
            return "8";
            else if(n==2)
            {
                return "88";

            }
            else if(n==3)
            {
                return "888";
            }
            else if(n==4)
            return "8888";
            else if(n==5)
            return "88888";
            else {
                ans[0] = '8';
                ans[1] = '8';
                ans[2] = '8';
                ans[ans.size()-1] = '8';
                ans[ans.size()-2] = '8';
                ans[ans.size()-3] = '8';
                return ans;
            }
        }
        else if(k==6)
        {
            if(n==1)
            return "6";
            else if(n==2)
            {
                return "66";
            }
            else if(n==3)
            {
                return "888";
            }
            else if(n==4)
            {
                return "8778";
            }
            else if(n==5){
                return "89898";
            }
            else if(n==6)
            {
                return "897798";
            }
            else 
            {
                string s(n,'9');
                if(n%2==0)
                {
                    s[0] = '8';
                    s[n-1] = '8';
                    s[n/2] = '7';
                    s[n/2-1]='7';
                }
                else 
                {
                    s[0] = '8';
                    s[n-1]='8';
                    s[n/2] = '8';
                }
                return s;

            }
        }
        else {
            if(n==1) return "7";
            if(n==2) return "77";
            if(n==3) return "959";
            string s;
            int sum=0;
            for(int i=0;i<n;i++){
                s.push_back('9');
                sum+=9;
            }
           if(isdiv7(s))
               return s;
            if(n%2){
            for(int i=0;i<10;i++){
                s[n/2-1]='9'-i;
                s[n/2+1]='9'-i;
                for(int i=1;i<10;i++){
                 s[n/2]='9'-i;
                 if(isdiv7(s))
                 return s;
                }
            }
            }
            else{
             for(int i=0;i<10;i++){
                s[n/2+1]='9'-i;
                s[n/2-2]='9'-i;
                for(int i=1;i<10;i++){
                s[n/2]='9'-i;
                s[n/2-1]='9'-i;
                 if(isdiv7(s))
                 return s;
                }
             }
            }
        }
        return "";
    }
};