class Solution {
public:
    bool isValidBST(TreeNode* root,long min, long max)
    {
    if(root==NULL)
    return true;
    if(root->val>=max||root->val<=min)
    return false;
    return isValidBST(root->left,min,root->val)&&isValidBST(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }        
};