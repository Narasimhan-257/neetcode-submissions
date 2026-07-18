class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int first = 0;
        int last = 0;
        int curr_len = 0;
        int max_l = 0;
        char ch;
        std::unordered_map<char,int>hmap;
        while(last < s.length())
        {
            ch = s[last];
            if(hmap.find(ch) == hmap.end())
            {
                curr_len = last - first + 1;
                hmap[ch]++;
                last++;
            }
            else
            {
                max_l = max(max_l,curr_len);
                hmap.erase(s[first]);
                first++;
                curr_len = 0;
            }

        }
        max_l = max(max_l,curr_len);
        return max_l;
        
    }
};
