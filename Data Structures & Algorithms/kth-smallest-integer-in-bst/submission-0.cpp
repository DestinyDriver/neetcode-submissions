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
    int ans;
    int tra(TreeNode* root,int &k,int ct){
        if(root==NULL)  return 0;

        int l=tra(root->left,k,ct);
        if(ct+l+1==k)  ans=root->val;
        int r=tra(root->right,k,ct+l+1);
        return l+r+1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int l=tra(root,k,0);
        return ans;
        
    }
};
