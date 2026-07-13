class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // int first = 0;
        // int last = first + 1;
        // vector<int>v1;
        // v1.resize(3);
        // vector<vector<int>>ans;
        // std::set<vector<int>>s1;
        // int sum = 0;
        // int target = 0;
        // while((first < nums.size()) && (last < nums.size()))
        // {
          
        //     sum = nums[first] + nums[last];
        //     for(int i = 0; i < nums.size(); i++)
        //     {
        //         if((i != first) && (i != last))
        //         {
        //             if((sum + nums[i]) == target)
        //             {
        //                 v1[0] = nums[first];
        //                 v1[1] = nums[last];
        //                 v1[2] = nums[i];
        //                 sort(v1.begin(),v1.end());
        //                 s1.insert(v1);
        //             }
        //         }

        //     }

        //     //first++;
        //     if(last == nums.size() - 1)
        //     {
        //         first++;
        //         last = first + 1;
        //     }
        //     else
        //     {
        //       last++;
        //     }

        // }

        // auto it = s1.begin();
        // while(it != s1.end())
        // {
        //     ans.push_back(*it);
        //     it++;
        // }


        // optimized approach O(n^2)
        vector<int>v1;
        v1.resize(3);
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int target = 0;
        int val = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size(); i++)
        {

            if((i > 0) && (nums[i] == nums[i-1]))
            {
                        
                continue;
            }
            else
            {
                val = nums[i];
                left = i + 1;
                right = nums.size() - 1;
                target = (-1)* val;
                while(left < right)
                {
                    
                    
                    
                        if((nums[left] + nums[right]) == target)
                        {
                            
                            v1[0] = nums[i];
                            v1[1] = nums[left];
                            v1[2] = nums[right];
                            ans.push_back(v1);
                            while((left < right) && (nums[left] == nums[left+1]))
                            {
                                left++;
                            }
                            
                            left++;
                            right--;

                        }
                        else if((nums[left] + nums[right]) > target)
                        {
                            right--;
                        }
                        else
                        {
                            left++;
                        }
                    
                }
            
            }
        }
        
    return ans; 
    }
};
