/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void convertSortedDLL(TreeNode* root,TreeNode* &head)){

    if(!root) return nullptr;

    convertSortedDLL(root->right,head);
    root->right = head;
    if(head) head->left = root;
    head = root;
    convertSortedDLL(root->left,head);
    

}

TreeNode* mergeLL(TreeNode* head1,TreeNode* head2){
    TreeNode*head = nullptr;
    TreeNode* tail = nullptr;

    while(head1 and head2){
        if (head1->data < head2->data){
            if(!head){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail=tail->right;
                head1=head1->right;

            }
        }
        else{
            if(!head){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail=tail->right;
                head2=head2->right;
            }

        }

    }

    while(head1){
        tail->right  = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
        while(head2){
        tail->right  = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
int countNodes(TreeNode* head){
    int cnt = 0;
    while(head){
        head = head->right;
        cnt++;
    }
}
TreeNode* TreeFromSortedLL(TreeNode* &head,int n){
    if(n<0 or !root) return NULL;

    TreeNode* left = TreeFromSortedLL(head,n/2);
    TreeNode* root = head;
    root->left = left;
    head = head->right;
    root->right = TreeFromSortedLL(head,n/2-1);
    return root;
}
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{   TreeNode* head1 = nullptr;
    convertSortedDLL(root1,head1);
    head1->left = nullptr;
    TreeNode* head2  = nuldlptr;
    convertSortedDLL(root2,head2);
    head1->left nullptr;

    TreeNode* head = mergeLL(head1,head2);

    return TreeFromSortedLL(head,countNodes(head));
}