#include<bits/stdc++.h>
using namespace std;
int heightOfBinaryTree(TreeNode<int> *root)
{
    if(root == NULL) return 0; 
        
        int lh = heightOfBinaryTree(root->left); 
        int rh = heightOfBinaryTree(root->right); 
        
        return 1 + max(lh, rh); 
}