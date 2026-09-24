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
    unordered_map<int,int>mp;
    TreeNode* tra(vector<int>&pre,vector<int>&in,int &ind,int l,int r){

        if(ind==pre.size()) return NULL;
        if(l>r) return NULL;

        TreeNode* root=new TreeNode(pre[ind]);
        int val=pre[ind];
        ind++;
        if(l==r)    return root;
        root->left=tra(pre,in,ind,l,mp[val]-1);
        root->right=tra(pre,in,ind,mp[val]+1,r);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]]=i;
        int ind=0;
        return tra(preorder,inorder,ind,0,inorder.size()-1);
        
    }
};
