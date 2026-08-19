class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool flag = false;
        // for(int i = 0; i < matrix.size(); i++)
        // {
        //     if((target >= matrix[i][0]) && (target <= matrix[i][n-1]))
        //     {
        //         while(start <= end)
        //         {
        //             mid = (start + end)/2;
        //             mid = mid%n;
        //             if(target == matrix[i][mid])
        //             {
        //                 flag = true;
        //                 return flag;
        //             }
        //             else if(target > matrix[i][mid])
        //             {
        //                 start = mid + 1;
        //             }
        //             else
        //             {
        //                 end = mid - 1;
        //             }

        //         }
        //     }
        // }

        int start = 0;
        int end = (matrix.size() * matrix[0].size() - 1);
        int mid = start + (end - start)/2;
        int mid_row = mid/matrix[0].size();
        int mid_col = mid%matrix[0].size();

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int mid_row = mid/matrix[0].size();
            int mid_col = mid%matrix[0].size();

            if(target == matrix[mid_row][mid_col])
            {
                flag = true;
                return flag;
            }
            else if(target > matrix[mid_row][mid_col])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return flag;
        
    }
};
