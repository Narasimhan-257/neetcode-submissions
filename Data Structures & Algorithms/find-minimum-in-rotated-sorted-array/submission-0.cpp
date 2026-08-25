class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(start < end)
        {   
            mid = (start + end)/2;
            if(nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    
        return nums[start];
        
    }
};
