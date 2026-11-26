class Solution {
public:
    int getSum(int a, int b) 
    {
        int carry = 0;
        int x = 0;
        int y = 0;
        int k = 0;
        int ans = 0;
        int final = 0;
        for(int k = 0; k <= 31; k++)
        {
            x = (a>>k) & 1U ;
            y = (b>>k) & 1U;
            ans = (x ^ y) ^ carry;
            carry = (x & y) | (x & carry) | (y & carry);

            final = final|((unsigned int)ans<<k);
        }


        return final;
        

    }
};
