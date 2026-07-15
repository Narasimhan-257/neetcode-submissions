class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        // ********* O(n^2) Approach *************
        // int max_area = 0;
        // int ele = 0;
        // int area = 0;
        // int n = heights.size() - 1;
        // for(int i = n; i >= 0; i--)
        // {
        //     int ele = heights[i];
        //     for(int j = 0; j < i; j++)
        //     {
        //        area = (i - j) * std::min(ele,heights[j]);
        //        if(area > max_area)
        //        {
        //           max_area = area;
        //        }
        //     }
        // }
        // return max_area;
       
      /********* O(n) Approach ***************/
     /*
      Start with the widest container and repeatedly move the shorter wall inward — since the shorter wall caps the height, no narrower pair using it can ever do better — recording the max area along the way.
Or the interview-compressed version: "Two pointers from both ends; always advance the pointer at the shorter line, because that wall can never form a larger container with anything closer."
    */ 
        int start = 0;
        int end = heights.size()-1;
        int max_area = 0;
        int area = 0;
        while(start < end)
        {
            area = ((end - start) * std::min(heights[start],heights[end]));
            if(area > max_area)
            {
                max_area = area;
            }

            if(heights[start] == heights[end])
            {
                start++;
                end--;
            }
            else if(heights[start] < heights[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        } 

        return max_area;
    }
};
