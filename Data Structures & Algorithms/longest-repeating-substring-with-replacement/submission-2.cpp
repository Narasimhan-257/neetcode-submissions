class Solution {
public:
    int characterReplacement(string s, int k) 
    {

        // Don't recompute max_freq after reducing the window. It won't contribute to in finding max length of a substring.
        int first = 0;
        int last = 0;
        int max_freq = 0;
        int max_l = 0;
        int count[26] = {0};
        char ch;
        int index = 0;
        int len = 0;
        while(last < s.length())
        {
            ch = s[last];
            index = ch - 'A';
            count[index]++;
            max_freq = max(max_freq, count[index]);
            len = last - first + 1;
            if((len - max_freq) <= k)
            {
                max_l = max(len,max_l);
            }
            else
            {
                ch = s[first];
                index = ch - 'A';
                count[index]--;
                first++;
            }
            last++;
        }

        return max_l;
        
    }
};
