class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // same as Linked List cycle detection Algorithm.
        // Floyd cycle detection Algorithm
        int slow = 0;
        int fast = 0;
        //using do while because both slow and fast starting at 0.    Algo has to pass atleast one Iteration
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

       // Finding the starting point of cycle
        fast = 0;
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

       return slow;
        
    }
};
