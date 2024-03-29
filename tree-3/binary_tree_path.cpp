class Solution {
public:
    void binaryTreePaths(vector<string>& ans, TreeNode* root, string s) {
        if(!root->left && !root->right) {
        ans.push_back(s);
        return;
    }

    if(root->left) binaryTreePaths(ans, root->left, s + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(ans, root->right, s + "->" + to_string(root->right->val));
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(!root) return ans;
    
    binaryTreePaths(ans, root, to_string(root->val));
    return ans;
}
        
    
};