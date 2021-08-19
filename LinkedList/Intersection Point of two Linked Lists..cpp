int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1=0,len2=0;
    Node* root1 = head1;
    Node* root2 = head2;
        
    while(root1!=NULL){
        len1++;
        root1=root1->next;
    }

    while(root2!=NULL){
        len2++;
        root2=root2->next;
    }
    int diff = abs(len1-len2);
    if(len2>len1){
        
        int i=0;
        while(head2!=NULL and i!=diff){
            head2 = head2->next;
            i++;
        }
        }
    else if(len1>len2){
        int i=0;
        while(head1!=NULL and i!=diff){
            head1 = head1->next;
            i++;
        }
        
    }
    
    while(head2!=head1){
            head1=head1->next;
            head2=head2->next;
        }
    if(head1!=NULL) return head1->data;
    return -1;
}
