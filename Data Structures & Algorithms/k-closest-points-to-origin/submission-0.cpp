class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int>distance;
        vector<vector<int>>v1;
        v1.resize(k);
        vector<int>v2;
        v2.resize(2);
        int n = points.size();
        distance.resize(n);
        int sum = 0;
        std::priority_queue<std::pair<int,int>>max_heap;

        for(int i = 0; i < points.size(); i++)
        {
            sum = 0;
            for(int j = 0; j < 2; j++)
            {
             sum  += (points[i][j]-0)* (points[i][j]-0);          
            }
            distance[i] = sum;
        }

        for(int i = 0; i < n; i++)
        {
            std::pair<int,int>p1 = {distance[i],i};
            max_heap.push(p1);
            if(max_heap.size() > k)
            {
                max_heap.pop();
            }
        }

        for(int i = 0; i < k; i++)
        {
            int ele = max_heap.top().first;
            int index = max_heap.top().second;
            for(int j = 0; j < 2; j++)
            {
                v2[j] = points[index][j]; 
            }
            v1[i] = v2;
            max_heap.pop();
            
        }


         return v1;


        


    }
};
