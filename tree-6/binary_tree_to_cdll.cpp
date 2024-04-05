class Solution
{
  public:
   Node *prev=NULL;
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return root;
        Node *head=bToDLL(root->left);
        if(prev==NULL)
        head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bToDLL(root->right);
        return head;
        
    }
    Node *bTreeToCList(Node *root)
    {                                       
      root=bToDLL(root);
      Node *curr=root;
      while(curr->right!=NULL){
          curr=curr->right;
      }
      curr->right=root;
      root->left=curr;
      return root;
    }
   
};