class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int tank=0,total=0,index;
       for(int i=0;i<n;i++){
           int consume = p[i].petrol - p[i].distance;
           tank+=consume;
           if(tank < 0){
               index = i+1;
               tank=0;
           }
           total+=consume;
       }
       if(total < 0)
       return -1;
       return index;
    }
};