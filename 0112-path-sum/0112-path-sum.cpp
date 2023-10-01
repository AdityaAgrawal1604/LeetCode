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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root&&(!root->left)&&(!root->right)&& (targetSum==(root->val))) return true;
        // if(!root&&(targetSum==0)) return true;
        if(!root) return false;
        if(root->right&&root->left) return (hasPathSum(root->right,targetSum-(root->val))||hasPathSum(root->left,targetSum-(root->val)));
        if(root->left) return hasPathSum(root->left,targetSum-(root->val));
        if(root->right) return hasPathSum(root->right,targetSum-(root->val));
        return false;
    }
};