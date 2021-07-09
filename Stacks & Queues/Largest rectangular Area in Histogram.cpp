class Solution {
public:
    void fillrightBoundary(vector<int>& arr, int rb[], int n){
        rb[n-1] = n;
        stack<int> s;
        s.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(s.size()>0 and arr[s.top()] >= arr[i]){ //badon ko pop kardo cuz chote hi boundary banenge
                s.pop();
            }
            if(s.size() == 0)
            rb[i] = n;
            else
            rb[i] = s.top();
            
            s.push(i);
        }
        return;
    }
    
    void fillleftBoundary(vector<int>& arr, int lb[], int n){
        lb[0] = -1;
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<n;i++){
            while(s.size()>0 and arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.size() == 0)
            lb[i] = -1;
            else
            lb[i] = s.top();
            
            s.push(i);
        }
        return;
    }
    
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int rb[n];
        int lb[n];
        fillrightBoundary(arr,rb,n);
        fillleftBoundary(arr,lb,n);
        
        long long ma=INT_MIN;
        for(int i=0;i<n;i++){
            long long width = rb[i] - lb[i] - 1;
            long long area = arr[i] * width;
            ma=max(ma,area);
        }
        return ma;
        
    }
};