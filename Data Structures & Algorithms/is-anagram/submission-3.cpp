class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int count[26];
        bool flag = true;

        for(int i = 0; i < 26; i++)
        {
            count[i] = 0;
        }

        int index = 0;
        for(int  i = 0;  i < s.length(); i++)
        {
            index = static_cast<int>(s[i]) - 97;
            count[index]++;

        }
        
        for(int j = 0; j < t.length(); j++)
        {
            index = static_cast<int>(t[j]) - 97;
            count[index]--;
        }

        for(int k = 0; k < 26; k++)
        {
            if(count[k] != 0)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};
