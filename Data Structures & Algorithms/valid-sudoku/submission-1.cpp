class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int rmap[9][10] = {0};
        int cmap[9][10] = {0};
        int box_map[9][10] = {0};
        bool flag = true;
        int val = 0;
        int box_num = 0;
        int b_x = 0;
        int b_y = 0;
        for(int i = 0; i < board.size(); i++)
        {
            for(int  j = 0; j < board[0].size(); j++)
            {
                b_x = i/3;
                b_y = j/3;
                box_num = (b_x)*3 + b_y;
                if(board[i][j] != '.')
                {
                    val = board[i][j] - '0';
                
                    if((rmap[i][val] == 0) && (cmap[j][val] == 0) && (box_map[box_num][val] == 0))
                    {
                        rmap[i][val] = 1;
                        cmap[j][val] = 1;
                        box_map[box_num][val] = 1;
                    }
                    else
                    {
                        std::cout<<i<<" "<<j<<"\n";
                        flag = false;
                        break;
                    }
                }
            }

            if(flag == false)
            {
                break;
            }
        }

        return flag;
    }
};
