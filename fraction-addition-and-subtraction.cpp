class Solution {
public:
    string fractionAddition(string s) {
        int numerator = 0, denominator = 1;  
        int n = s.length();
        int i = 0;

        while (i < n) {
            int sign = 1; 
            if (s[i] == '-' || s[i] == '+') {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

            
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            num *= sign; 

            i++;

           
            int denom = 0;
            while (i < n && isdigit(s[i])) {
                denom = denom * 10 + (s[i] - '0');
                i++;
            }

            
            numerator = numerator * denom + num * denominator;
            denominator *= denom;

            
            int gcd = __gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
