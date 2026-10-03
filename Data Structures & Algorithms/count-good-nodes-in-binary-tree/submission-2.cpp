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
   void GoodNode(TreeNode* root, int curr_max, int& count)
   {
        if(root == nullptr)
        {
            return;
        }
        if(curr_max <= root->val)
        {
            curr_max = root->val;
            count++;
        }
        GoodNode(root->left,curr_max,count);
        GoodNode(root->right,curr_max,count);
        
   }
    int goodNodes(TreeNode* root) 
    {

        int curr_max = INT_MIN;
        int count = 0;
        GoodNode(root,curr_max,count);

        return count;
        
    }
};
