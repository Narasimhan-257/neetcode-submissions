class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int first = 0;
        int last = first + 1;
        vector<int>v1;
        v1.resize(3);
        vector<vector<int>>ans;
        std::set<vector<int>>s1;
        int sum = 0;
        int target = 0;
        while((first < nums.size()) && (last < nums.size()))
        {
          
            sum = nums[first] + nums[last];
            for(int i = 0; i < nums.size(); i++)
            {
                if((i != first) && (i != last))
                {
                    if((sum + nums[i]) == target)
                    {
                        v1[0] = nums[first];
                        v1[1] = nums[last];
                        v1[2] = nums[i];
                        sort(v1.begin(),v1.end());
                        s1.insert(v1);
                    }
                }

            }

            //first++;
            if(last == nums.size() - 1)
            {
                first++;
                last = first + 1;
            }
            else
            {
              last++;
            }

        }

        auto it = s1.begin();
        while(it != s1.end())
        {
            ans.push_back(*it);
            it++;
        }

       return ans; 
    }
};
