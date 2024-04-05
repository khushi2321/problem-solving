class Solution {
public:
    TreeNode* helper(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            TreeNode* root=new TreeNode(head->val);
            return root;
        } 
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=slow;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        prev->next=NULL;
        
        root->left=helper(head);
        root->right=helper(slow->next);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};