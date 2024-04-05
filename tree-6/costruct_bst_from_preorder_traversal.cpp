class Solution {
private:
    TreeNode* buildtree(int min, int max, vector<int>&preorder,int &i){
        if(i>=preorder.size() || preorder[i] < min || preorder[i] > max){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left=buildtree(min,root->val,preorder,i);
        root->right=buildtree(root->val,max,preorder,i);
        return root;
    } 
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildtree(INT_MIN,INT_MAX,preorder,i);
    }
};