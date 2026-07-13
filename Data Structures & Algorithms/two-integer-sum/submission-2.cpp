class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int,int>hmap;
        std::vector<int>ans;
        int val = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            val = target - nums[i];
            if(hmap.find(val) == hmap.end())
            {
                hmap[nums[i]] = i;
            }
            else
            {
                auto it = hmap.find(val);
                ans.push_back(it->second);
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
