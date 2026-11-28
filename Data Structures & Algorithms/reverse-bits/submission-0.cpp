class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int k = 0;
        uint32_t ans = 0;
        uint32_t a = 0;
        uint32_t b = 0;
        for(int i = 31; i >= 0; i--)
        {
            a = (n>>k)&1U;
            //b = b|a;
            ans = (a<<i)|ans;
            k++;
        }
        return ans;
    }
};
