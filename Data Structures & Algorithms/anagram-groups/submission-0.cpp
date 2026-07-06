class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        string s;
        vector<vector<string>>ans;
        std::unordered_map<string,vector<string>>hmap;
        for(int i = 0; i < strs.size(); i++)
        {
            s = strs[i];
            sort(s.begin(), s.end());
            hmap[s].push_back(strs[i]);
        }

        for(auto it = hmap.begin(); it != hmap.end(); it++)
        {
            ans.push_back(it->second);
        }


        return ans;
    }
};
