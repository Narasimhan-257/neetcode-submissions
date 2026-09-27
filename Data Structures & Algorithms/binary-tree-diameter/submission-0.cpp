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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int max_diameter;
        max_diameter = 0;
        calc_depth(root,max_diameter);
        return max_diameter;
        
    }

    int calc_depth(TreeNode* root, int& max_diameter)
    {
        if(root == NULL)
        {
            return 0;
        }

            int ld = calc_depth(root->left, max_diameter);
            int rd = calc_depth(root->right, max_diameter);
            max_diameter = std::max(max_diameter, ld + rd);
            return 1 + max(ld,rd);    
        

    }
};
