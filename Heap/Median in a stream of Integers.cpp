class Solution
{
    public:
    //Function to push heap.
    priority_queue<double,vector<double>,greater<double>> min_heap;
    priority_queue<double> max_heap;
    void pushHeap(int &x)
    {
        if(max_heap.size() == min_heap.size()){
            if(max_heap.size() == 0){
            max_heap.push(x);
            return;
            }
            
            if(x < max_heap.top())
            max_heap.push(x);
            else
            min_heap.push(x);
        }
        else{
            if(max_heap.size() > min_heap.size()){
                if(x>=max_heap.top())
                min_heap.push(x);
                else{
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                    max_heap.push(x);
                }
            }
            else{
                if(x<=min_heap.top())
                max_heap.push(x);
                else{
                    int temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                    min_heap.push(x);
                }
            }
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        return;
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(max_heap.size() - min_heap.size() == 0)
        return (max_heap.top() + min_heap.top())/2.0;
        else if(max_heap.size() > min_heap.size())
        return max_heap.top();
        else
        return min_heap.top();
    }
};