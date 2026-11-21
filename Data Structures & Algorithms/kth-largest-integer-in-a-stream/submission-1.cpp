class KthLargest 
{
public:
    int m_size;
    std::priority_queue<int,std::vector<int>,std::greater<int>>min_heap;

    KthLargest(int k, vector<int>& nums) 
    {
        m_size = k;
        for(int i = 0; i < nums.size(); i++)
        {
            min_heap.push(nums[i]);
            if(min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
    }
    
    int add(int val) 
    {
        int ele = 0;
        min_heap.push(val);
        if(min_heap.size() > m_size)
        {
           min_heap.pop();
          
        }
        ele = min_heap.top();
        return ele;
        
    }
};
