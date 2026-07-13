class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int start = 0;
        int end = numbers.size() - 1;
        int sum = 0;
        vector<int>ans;
        ans.resize(2);
        while(start < end)
        {
            sum = numbers[start] + numbers[end];
            if(sum == target)
            {
                ans[0] = start + 1;
                ans[1] = end + 1;
                break;
            }
            else
            {
                if(sum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }

        return ans;

    }
};
