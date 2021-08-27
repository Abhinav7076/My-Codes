int minJumps(int arr[], int n){
    // Your code here
    if (n <= 1)
        return 0;
 
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
 
    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];
    int steps = arr[0];
    int jumps=1;
    for(int i=1;i<n;i++){
        if(i==n-1)
        return jumps;
        maxReach = max(maxReach, i+arr[i]);
        steps--;
        if(steps==0){
            if(i>=maxReach) return -1;
            jumps++;
            steps=maxReach-i;
        }
    }
    
}