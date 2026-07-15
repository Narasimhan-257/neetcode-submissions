class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int max_area = 0;
        int ele = 0;
        int area = 0;
        int n = heights.size() - 1;
        for(int i = n; i >= 0; i--)
        {
            int ele = heights[i];
            for(int j = 0; j < i; j++)
            {
               area = (i - j) * std::min(ele,heights[j]);
               if(area > max_area)
               {
                  max_area = area;
               }
            }
        }
        return max_area;

    }
};
