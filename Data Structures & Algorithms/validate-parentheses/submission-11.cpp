class Solution {
public:
    bool match_parentheses(char ch1, char ch2)
    {
        bool flag = false;
        if((ch1 == '(') && (ch2 == ')'))
        {
            flag = true;
        }
        else if((ch1 == '[') && (ch2 == ']'))
        {
            cout<<"Inside else if:"<<"\n";
            flag = true;
        }
        else if((ch1 == '{') && (ch2 == '}'))
        {
            flag = true;
        }

        return flag;
    }
    bool isValid(string s) 
    {
        stack<char>s1;
        char ch1;
        char ch2;
        bool flag = false;
        if(s.length() == 1)
        {
            return flag;
        }
        else
        {
            for(int i = 0; i < s.length(); i++)
            {
                if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                {
                    s1.push(s[i]);
                }

                else
                {
                    if(!s1.empty())
                    {
                        char ch = s1.top();
                        s1.pop();
                        flag = match_parentheses(ch,s[i]);
                        std::cout<<"flag is true:"<<flag<<"\n";
                        if(flag == false)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout<<"Inside else:"<<"\n";
                        flag = false;
                        break;
                    }
                }
                // if((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
                // {
                //     s1.push(s[i]);
                //     if(!s1.empty())
                //     {
                //         ch1 = s1.top();
                //         s1.pop();
                //         flag = match_parentheses(ch1,s[i]);
                //         if(flag == false)
                //         {
                //             break;
                //         }

                //     }
    
                // }


            }

            // if(s1.empty() && flag == false)
            // {
            //     flag = false;
            // }
            if(!s1.empty())
            {
                flag = false;
            }

        }

        return flag;
        
    }
};
