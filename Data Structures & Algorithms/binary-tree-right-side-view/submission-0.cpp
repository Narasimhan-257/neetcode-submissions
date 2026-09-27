/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//In Level order Traversal only push the elements to ans vector if it is the last element of parent. In for loop check (if i == size-1) adnd then fill the answer vector.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

         queue<TreeNode*>q1;
        vector<int>res;

        if(root != NULL)
        {
        q1.push(root);
        TreeNode* temp = root;
        int size = 0;

        while(!q1.empty())
        {
            size = q1.size();
            for(int i = 0; i < size; i++)
            {
                temp = q1.front();
                q1.pop();
                if(temp->left)
                {
                    q1.push(temp->left);
                }
                if(temp->right)
                {
                    q1.push(temp->right);
                }
                if(i == size-1)
                {
                    res.push_back(temp->val);
                }
            }
        }
        }
        return res;
        
    }
};
