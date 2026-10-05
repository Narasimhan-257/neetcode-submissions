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

   std::unordered_map<int,int>inorder_map;
    int pre_index = 0;
    TreeNode* build(vector<int>& preorder, int start, int end)
    {
        //base case No Nodes to insert
        if(start > end)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_index]);
        pre_index++;
        int mid = inorder_map[root->val];
        root->left = build(preorder,start,mid-1);
        root->right = build(preorder,mid+1,end);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }
        
        return build(preorder,0, inorder.size()-1);

        
    }
};
