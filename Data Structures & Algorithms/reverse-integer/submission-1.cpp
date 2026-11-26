class Solution {
public:
    int reverse(int x) 
    {
        int digit = 0;
        int rev = 0;
        int num = x;
        if(x < 0)
        {
            num = (-1)*x;
        }
        while(num > 0)
        {
            digit = num % 10;
            if(rev > INT_MAX/10)
            {
                return 0;
            }
            else if(rev == INT_MAX/10)
            {
                if(digit > INT_MAX%10)
                {
                    return 0;
                }
                else
                {
                    rev = (rev * 10) + digit;
                }
            }
            else if(rev < INT_MAX/10)
            {
                rev = (rev * 10) + digit;
            }

            num = num/10;
        }
        if(x < 0)
        {
            rev = (-1)*rev;
        }
        return rev;
    }
};
