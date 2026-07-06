class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int>hmap;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hmap.find(nums[i]) == hmap.end())
            {
                hmap.insert(nums[i]);
            }
            else
            {
                flag = true;
                break;
            }
        }
        return flag;
        
    }
};