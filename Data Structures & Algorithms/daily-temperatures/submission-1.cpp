class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int>s1;
        s1.push(0);
        int n = temperatures.size();
        vector<int>result;
        result.resize(n);
        int top_index = 0;
        int diff = 0;
        for(int i = 1; i < temperatures.size(); i++)
        {
            while(!s1.empty())
            {
               top_index = s1.top();
               if(temperatures[i] > temperatures[top_index])
               {
                   diff = i - top_index;
                   result[top_index] = diff;
                   s1.pop();
               }
               else
               {
                  break;
               }

            }
            s1.push(i);

        }

        while(!s1.empty())
        {
            top_index = s1.top();
            result[top_index] = 0;
            s1.pop();
        }

       return result;
    }
};
