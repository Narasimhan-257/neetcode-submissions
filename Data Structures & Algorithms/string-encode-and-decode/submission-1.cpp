class Solution {
public:

   string find_len_char(int num)
   {
       string p = "";
       while(num > 0)
       {
          p += (num % 10) + '0';
          num = num/10;
       }
       if(p.length()  > 1)
       {
          std::reverse(p.begin(), p.end());
       }
       return p;
   }

    string encode(vector<string>& strs) 
    {
        string encode = "";
        int len = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            len = strs[i].length();
            encode += find_len_char(len);
            encode += '*';
            for(int j = 0; j < strs[i].length(); j++)
            {
                encode += strs[i][j];
            }
        }
        return encode;

    }

    int find_len(int index, string s, int& len)
    {
        int i = 0;
        for(i = index; s[i] != '*'; i++)
        {
            len = (len * 10) + (s[i] - '0');
        }
        
        return i;
    }

    vector<string> decode(string s) 
    {
        vector<string>strs;
        string q = "";
        int start = 0;
        int j = 0;
        for(int i = 0; i < s.length(); )
        {
            int len = 0;
            q = "";
            start = find_len(i, s, len);
            for(j = start + 1; j < (start + 1) + len; j++)
            {
                q += s[j];
            }
            i = j;
            strs.push_back(q);
        } 
        return strs;
    }
};
