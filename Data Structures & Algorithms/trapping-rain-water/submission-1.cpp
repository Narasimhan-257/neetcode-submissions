class Solution {
public:
    int trap(vector<int>& height) 
    {
    
     //O(n) --> TC and O(n) --> SC

    //   const int n = height.size();
    //   vector<int>left_max_array(n);
    //   vector<int>right_max_array(n);
      
    //   int trapped = 0;
      
      
      
    //   left_max_array[0] = height[0];
      
    //   right_max_array[n-1] = height[n-1];
      
      
      
      
      
    //   for(int i = 1; i < n; i++)
      
    //   {
      
    //     left_max_array[i] = max(left_max_array[i-1], height[i]);
      
    //   }
      
      
      
    //   for(int i = n-2; i >= 0; i--)
      
    //   {
      
    //      right_max_array[i] = max(right_max_array[i+1],height[i]);
      
    //   }
      
      
      
      
      
    //   for(int i = 0; i < n; i++)
    //   {
      
    //     trapped += (min(left_max_array[i], right_max_array[i]) - height[i]);
      
    //   } 


   // Two Pointer O(n) TC and O(1) SC

    int trapped = 0;

    int left = 0;
    int right = height.size() - 1;

    int max_left = 0;
    int max_right = 0;

    while(left <= right)
    {
        if(height[left] <= height[right])
        {
            if(max_left > height[left])
            {
                trapped += max_left - height[left];
            }
            else
            {
                max_left = height[left];
            }
            left++;
        }
        else
        {
            if(max_right >= height[right])
            {
                trapped += max_right - height[right];
            }
            else
            {
                max_right = height[right];
            }
            right--;
        }

    }

      
      return trapped;
              
    }
  
};
