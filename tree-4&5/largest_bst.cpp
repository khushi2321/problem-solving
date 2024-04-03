class Solution{
    public:
    int solve(Node* root,int &maxval,int &minval,int &s){
        if(root==NULL){
            return 0;
        }
        int lmax = INT_MIN;
        int lmin = INT_MAX;
        int rmax = INT_MIN;
        int rmin = INT_MAX;
        int l = solve(root->left,lmax,lmin,s);
        int r = solve(root->right,rmax,rmin,s);
        if(l==-1 || r==-1 || (root->left && lmax >= root->data) || (root->right && rmin <= root->data)){
            return -1;
        }
        minval = root->left ? lmin : root->data;
        maxval = root->right ? rmax : root->data;
        int size = l + r + 1;
        s = max(s, size);
        return size;
    }
    int largestBst(Node *root)
    {
        int maxval = INT_MIN;
        int minval = INT_MAX;
        int c = 0;
        solve(root,maxval,minval,c);
        return c;
    }
};
