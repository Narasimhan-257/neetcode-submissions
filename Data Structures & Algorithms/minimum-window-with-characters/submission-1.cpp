class Solution {
public:
    string minWindow(string s, string t) 
    {
        int count[128] = {0};
        int min_l = INT_MAX;
        int left = 0;
        int right = 0;
        int required = 0;
        int ind = 0;
        int index = 0;
        int curr_len = 0;
        int start = 0;
        string p = "";
        for(int i = 0; i < t.length(); i++)
        {
            int ind = t[i];
            count[ind]++;
            required++; 
        }
        while(right < s.length())
        {
            index = s[right];
            
            if(count[index] > 0)
            {
               
                required--;
            } 
            count[index]--;
            while(required == 0)
            {
                curr_len = right - left + 1;
                min_l = min(curr_len, min_l);
                if(min_l == curr_len)
                {
                    start = left;
                }
                // if(curr_len < min_l)
                // {
                //     min_l = curr_len;
                //     start = left;
                // }

                ind = s[left];
                count[ind]++;
                if(count[ind] > 0)
                {
                    required++;
                }
                left++;
            }
            right++;
        }

        if(min_l == INT_MAX)
        {
            p = "";
        }
        else
        {
            p = s.substr(start,min_l);
        }
        return p;
    }
};
