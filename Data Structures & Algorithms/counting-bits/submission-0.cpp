class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>freq;
        freq.resize(n+1);
        int count = 0;
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            count = 0;
            for(int j = 0; j < 32; j++)
            {
                ans = (i>>j) & 1U ;
                if(ans == 1)
                {
                    count++;
                }
            }
            freq[i] = count;
        }
        return freq;
    }
};
