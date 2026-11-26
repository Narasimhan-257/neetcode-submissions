class Solution {
public:
    int reverse(int x) 
    {
        int digit = 0;
        int rev = 0;
        int num = x;

        while(num != 0)
        {
            digit = num % 10;
            if((rev > INT_MAX/10) || (rev < INT_MIN/10))
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
            else if(rev == INT_MIN/10)
            {
                if(digit < INT_MIN%10)
                {
                    return 0;
                }
                else
                {
                    rev = (rev * 10) + digit;
                }
            }

            else
            {
                rev = (rev * 10) + digit;
            }

            num = num/10;
        }

        return rev;
        
    }
};
