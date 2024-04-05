class Solution
{
    public:
    bool isPresent(Node* root , int data){
        if(root == NULL){
            return false;
        }
        if(data == root->data){
            return true;
        }
        if(data < root->data){
            return isPresent(root->left , data);
        }
        if(data > root->data){
            return isPresent(root->right , data);
        }
    }
    void solve(Node *root1, Node *root2 , vector<int>& v){
        if(root1 == NULL){
            return ;
        }
        solve(root1->left , root2 , v);
        int d = root1->data;
        if(isPresent(root2 , d)){
            v.push_back(d);
        }
        solve(root1->right , root2 , v);
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>v;
        solve(root1 , root2 , v);
        sort(v.begin() , v.end());
        return v;

    }
};
