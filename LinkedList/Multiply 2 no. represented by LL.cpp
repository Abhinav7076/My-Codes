long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long num1=0,num2=0;
  while(l1!=NULL){
      int d = l1->data;
      num1 = (num1*10 + d)%1000000007;
        l1 = l1->next;
    }
    while(l2!=NULL){
      int d = l2->data;
      num2 = (num2*10 + d)%1000000007;
        l2 = l2->next;
    }
    
    return ((num1%1000000007)*(num2%1000000007))%1000000007;
    
    
        

}