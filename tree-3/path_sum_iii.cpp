class Solution {
public:
int count=0;
long long sum=0;
        void pathsumsolver(TreeNode* &root,int &targetSum){
        if(root==NULL)
            return;
            sum+=root->val;
            if(sum==targetSum){
                count++;
        }
        pathsumsolver(root->left,targetSum);
        pathsumsolver(root->right,targetSum);
        sum-=root->val;
    }
    int pathSum(TreeNode* &root, int &targetSum) {
        if(root==NULL)
            return 0;
        pathsumsolver(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};