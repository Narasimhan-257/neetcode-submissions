class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int>s1;
        int n = heights.size();
        s1.push(0);
        int width = 0;
        int area = 0;
        int max_area = 0;
        int top = 0;
        for(int i = 1; i<n; i++)
        {

            while((!s1.empty()) && (heights[i] <= heights[s1.top()]))
            {
                top = s1.top();
                s1.pop();
                if(s1.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - (s1.top()) - 1;
                }
                area = heights[top]*width;
                if(max_area < area)
                {
                    max_area = area;
                }
            }
            

            s1.push(i);
            
        }

        while(!s1.empty())
        {
            top = s1.top();
            s1.pop();
            if(s1.empty())
            {
                width = n;
            }
            else
            {
                width = n - s1.top()-1;
            }
            area = heights[top] * width;
            if(max_area < area)
            {
                max_area = area;
            }
        }
        return max_area;
    }
};
