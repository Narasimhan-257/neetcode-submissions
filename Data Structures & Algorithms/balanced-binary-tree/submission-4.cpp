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

class Solution {
public:
    int check_height(TreeNode* root)
    {
        int lh = 0;
        int rh = 0;

        if(root == nullptr)
        {
            return 0;
        }
        
        if(root->left)
        {
          lh = check_height(root->left);
        }
        if(lh == -1)
        {
            return -1;
        }
        if(root->right)
        {
          rh = check_height(root->right);
        }

        if(rh == -1)
        {
            return -1;
        }

        if(abs(rh-lh) > 1)
        {
            return -1;
        }
        
        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) 
    {
        bool balanced = false;
        if(check_height(root) != -1)
        {
            balanced = true;
        }

        return balanced;

        
    }
};
