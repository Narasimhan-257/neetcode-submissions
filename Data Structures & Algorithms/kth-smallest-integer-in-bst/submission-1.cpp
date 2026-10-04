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
    void inorder(TreeNode* root, vector<int>& v1, int& counter,int k)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left,v1,counter,k);
        v1.push_back(root->val);
        counter++;
        if(counter == k)
        {
            return;
        }
        inorder(root->right,v1,counter,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
       vector<int>v1;
        int counter = 0;
        inorder(root, v1, counter,k);
        return v1[k-1];
        
    }
};
