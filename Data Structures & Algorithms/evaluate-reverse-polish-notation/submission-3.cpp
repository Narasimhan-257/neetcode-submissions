class Solution {
public:
   int calc_op(int a, int b, string op)
   {
      int ans = 0;
      if(op == "+")
      {
        ans = a + b;
      }
      else if(op == "-")
      {
        ans = a - b;
      }
      else if(op == "*")
      {
          ans = a * b;
      }
      else if(op == "/")
      {
          ans = a/b; 
      }
      return ans;
   }
    int evalRPN(vector<string>& tokens) 
    {
        stack<string>s1;
        int ans = 0;
        int val = 0;
        int a = 0;
        int b = 0;
        if(tokens.size() == 1)
        {
            ans = std::stoi(tokens[0]);
        }
        else
        {
            for(int i = 0; i < tokens.size(); i++)
            {
                if((tokens[i] == "+") || (tokens[i] == "-") || (tokens[i] == "*") ||                    (tokens[i] == "/"))
                {
                    
                    b = std::stoi(s1.top());
                    s1.pop();
                    a = std::stoi(s1.top());
                    s1.pop();
                    ans = calc_op(a,b,tokens[i]);
                    s1.push(std::to_string(ans));
                }   
                else
                {
                   s1.push(tokens[i]);
                }
                
            }
        }
        return ans;
        
    }
};
