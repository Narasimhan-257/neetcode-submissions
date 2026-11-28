class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;
        for(int i = 0; i < 32; i++)
        {
            if((n>>i)&1U == 1U)
            {
                count++;
            }
        }

        return count;

    }
};
