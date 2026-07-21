class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        bool flag = 0;
        int first  = 0;
        int last = 0;
        int count[26] = {0};
        int index = 0;
        int index2 = 0;
        int index3 = 0;
        int required = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            index = s1[i] - 97;
            count[index]++;
            required++; 
        }
        while(last < s2.length())
        {
            index2 = s2[last] - 97;
            if(count[index2] > 0)
            {
                required--;
            }
            count[index2]--;

            if(((last - first) + 1) == s1.length())
            {
                if(required == 0)
                {
                    flag = true;
                    break;
                }
                else
                {
                    index3 = s2[first] - 97;
                    if(count[index3] >= 0)
                    {
                        required++;
                    }
                    count[index3]++;
                    first++;
                }
            }
            last++;
        }
        return flag;
    }
};
