class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // string s;
        // vector<vector<string>>ans;
        // std::unordered_map<string,vector<string>>hmap;
        // for(int i = 0; i < strs.size(); i++)
        // {
        //     s = strs[i];
        //     sort(s.begin(), s.end());
        //     hmap[s].push_back(strs[i]);
        // }

        // for(auto it = hmap.begin(); it != hmap.end(); it++)
        // {
        //     ans.push_back(it->second);
        // }

        // optimized approach without sorting

        std::map<vector<int>,vector<string>>hmap;
        string s;
        vector<vector<string>>ans;
        vector<int>count(26,0);
        int index = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            fill(count.begin(), count.end(), 0);
            for(int j = 0; j < strs[i].size(); j++)
            {
               index = static_cast<int>(strs[i][j]) - 97;
               count[index] += 1;
            }
            hmap[count].push_back(strs[i]);
        }

        for(auto it = hmap.begin(); it != hmap.end(); it++)
        {
            ans.push_back(it->second);
        }


        return ans;
    }
};
