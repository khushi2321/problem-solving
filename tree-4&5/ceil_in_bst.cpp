int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int c=-1;
    while(root)
    {
        if(root->data==input) return input;
        else if(root->data<input) root=root->right;
        else
        {
            c=root->data;
            root=root->left;
        }
    }
    return c;
    
}