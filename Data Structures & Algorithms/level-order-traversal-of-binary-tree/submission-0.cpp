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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*>q1;
        vector<int>v1;
        vector<vector<int>>ans;
        q1.push(root);
        while(!q1.empty())
        {
            int size = q1.size();
            v1.clear();
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q1.front();
                q1.pop();
                if(temp != nullptr)
                {
                  v1.push_back(temp->val);
                  q1.push(temp->left);
                  q1.push(temp->right);
                }
            }
            if(v1.size() > 0)
            {
              ans.push_back(v1);
            }
        }
        return ans;
    }
};
