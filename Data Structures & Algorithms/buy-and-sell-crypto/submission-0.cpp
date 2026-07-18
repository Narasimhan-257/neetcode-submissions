class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int max = 0;
        int first = 0;
        int last = first + 1;
        int diff = 0;
        while(last < prices.size())
        {
            if(prices[last] < prices[first])
            {
                first = last;
                last++;
            }
            else
            {
                diff = prices[last] - prices[first];
                if(diff > max)
                {
                    max = diff;
                }
                last++; 
            }
        }

        return max;
        
    }
};
