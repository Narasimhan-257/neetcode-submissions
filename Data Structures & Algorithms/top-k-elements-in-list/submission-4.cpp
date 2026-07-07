class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //************* O(nlogn) Approach *****************
        // int value = 0;
        // std::unordered_map<int,int>hmap;
        // std::priority_queue<pair<int,int>>max_heap;
        // std::vector<int>ans;
        // pair<int,int>p;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     value = nums[i];
        //     hmap[value]++;
        // }
        // for(auto it = hmap.begin(); it != hmap.end(); it++)
        // {
        //     p.first = it->second;
        //     p.second = it->first;
        //     max_heap.push(p);
        // }
        // for(int i = 0; i < k; i++)
        // {
        //     p = max_heap.top();
        //     max_heap.pop();
        //     ans.push_back(p.second);
        // }
       
       //********** O(n) Approach *****************
       
        int n = nums.size();
        //Each element can repeat maximum n times. so we can create n + 1 sized array to store element in its frequency index.
        
        vector<vector<int>>rep;
        
        rep.resize(n+1);
       
        std::unordered_map<int,int>hmap;
        std::vector<int>ans;
        int value = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            value = nums[i];
            hmap[value]++;
        }
        
        for(auto it = hmap.begin(); it != hmap.end(); it++)
        {
            rep[it->second].push_back(it->first);
            
        }

        for(int i = rep.size()-1; i > 0; i--)
        {
            if(rep[i].size() != 0)
            {
                for(int j = 0; j < rep[i].size(); j++)
                {
                    if(count < k)
                    {
                      ans.push_back(rep[i][j]);
                      count++;
                    }
                }
            }
        }


        return ans;
        
    }
};
