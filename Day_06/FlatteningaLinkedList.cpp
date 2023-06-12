/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* head1, Node* head2){
    //base case
    if(head1 == NULL && head2 == NULL)return NULL;
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    //reursive case
    Node* res;
    if(head1->data < head2->data){
        res = head1;
        res->bottom = merge(head1->bottom,head2);
    }
    else{
        res = head2;
        res->bottom = merge(head1,head2->bottom);
    }
    return res;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL)return root;
   Node* head1 = root;
   Node* head2 = root->next;
   while(head2 != NULL){
       head1 = merge(head1,head2);
       head2 = head2->next;
   }
   return head1;
}