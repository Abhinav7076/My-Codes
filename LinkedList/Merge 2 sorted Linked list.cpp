struct Node* SortedMerge(struct Node* a, struct Node* b)
{
   if(a == NULL){
       return b;
   }
   
   if(b == NULL)
   {
       return a;
   }
  struct Node* result;
   
   if(a->data < b->data){
       result = a;
      result->next = SortedMerge(a->next,b);
   }else{
       result = b;
      result->next = SortedMerge(a,b->next);
   }
   
   return result;
}