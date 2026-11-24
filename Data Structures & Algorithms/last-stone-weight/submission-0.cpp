class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int>max_heap(stones.begin(), stones.end());
        int ele = 0;
        while(max_heap.size() > 1)
        {
            int a = max_heap.top();
            max_heap.pop();
            int b = max_heap.top();
            max_heap.pop();
            int diff = a- b;
            max_heap.push(diff);
        }
        
        ele = max_heap.top();
        max_heap.pop();
        return ele;
    }
};
