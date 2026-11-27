class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int ans = 0;
        int final_ans = 0;
       

        for(int i = 1; i <= nums.size(); i++)
        {
            ans = ans ^ i;
 
        }
        
        final_ans = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            
            final_ans = final_ans ^ nums[i];
            
        }

        final_ans = (final_ans ^ ans);

        return final_ans;
        
    }
};
