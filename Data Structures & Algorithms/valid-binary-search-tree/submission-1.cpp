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
    bool tra(TreeNode* root, int l,int r){
        if(root==NULL)  return true;
        if(!((root->val>l &&root->val<r)))  return false;
        if(!tra(root->left,l,root->val))    return false;
        if(!tra(root->right,root->val,r))   return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return tra(root,INT_MIN,INT_MAX);
        
    }
};
