class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(isalnum(s[i]))
            {
                str += std::tolower(s[i]);
            }
        }
       std::cout<<str<<"\n";
        int first  = 0;
        int last = str.length() - 1;
        bool flag = true;
        while(first < last)
        {
            if(str[first] != str[last])
            {
                std::cout<<"first:"<<first<<"\n";
                std::cout<<"last:"<<last<<"\n";
                flag = false;
                break;
            }
            first++;
            last--;
        }
        return flag;
        
    }
};
