class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int max_pile = 0;
        int max_hrs = 0;
        int max_num = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            if(piles[i] > max_pile)
            {
                max_pile = piles[i];
            }
        }
        std::cout<<"max_pile:"<<max_pile<<"\n";
        int start = 1;
        int end = max_pile;
        int mid = 0;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            std::cout<<"mid:"<<mid<<"\n";
            max_hrs = 0;
            for(int i = 0; i < piles.size(); i++)
            {
               // if(piles[i] >= mid)
               // {
                  max_hrs = max_hrs + ceil(static_cast<double>(piles[i])/mid);
               // }
     //           else
     //           {
     //               max_hrs++;
     //           }
            }
            cout<<"max_hrs:"<<max_hrs<<"\n";
            if(max_hrs <= h)
            {
                max_num = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return max_num;
    }
};
