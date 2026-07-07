class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int value = 0;
        std::unordered_map<int,int>hmap;
        std::priority_queue<pair<int,int>>max_heap;
        std::vector<int>ans;
        pair<int,int>p;
        for(int i = 0; i < nums.size(); i++)
        {
            value = nums[i];
            hmap[value]++;
        }
        for(auto it = hmap.begin(); it != hmap.end(); it++)
        {
            p.first = it->second;
            p.second = it->first;
            max_heap.push(p);
        }
        for(int i = 0; i < k; i++)
        {
            p = max_heap.top();
            max_heap.pop();
            ans.push_back(p.second);
        }
        return ans;
        
    }
};
