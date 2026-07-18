class Solution {
public:
    int trap(vector<int>& height) 
    {
    
      const int n = height.size();
      vector<int>left_max_array(n);
      vector<int>right_max_array(n);
      
      int trapped = 0;
      
      
      
      left_max_array[0] = height[0];
      
      right_max_array[n-1] = height[n-1];
      
      
      
      
      
      for(int i = 1; i < n; i++)
      
      {
      
        left_max_array[i] = max(left_max_array[i-1], height[i]);
      
      }
      
      
      
      for(int i = n-2; i >= 0; i--)
      
      {
      
         right_max_array[i] = max(right_max_array[i+1],height[i]);
      
      }
      
      
      
      
      
      for(int i = 0; i < n; i++)
      {
      
        trapped += (min(left_max_array[i], right_max_array[i]) - height[i]);
      
      } 
      
      return trapped;
              
    }
  
};
