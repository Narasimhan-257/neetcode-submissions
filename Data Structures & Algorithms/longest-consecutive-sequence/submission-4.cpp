class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>s1;
        int start = 0;
        int curr_len = 0;
        int len = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            s1.insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(s1.find(nums[i] - 1) == s1.end())
            {
                auto it = s1.find(nums[i]);
                start = *it;
                curr_len = 1;
                len = max(curr_len, len);
                while(s1.find(start + 1) != s1.end())
                {
                    curr_len++;
                    len = max(curr_len, len);
                    start = start + 1;
                }

            }
        }

        return len;

    }
};
