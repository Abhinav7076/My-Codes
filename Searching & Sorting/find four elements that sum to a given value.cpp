//GFG
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int> > v;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                while(l<r){
                    // cout<<arr[j]<<" "<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                    if((arr[i]+arr[j]+arr[l]+arr[r]) == target){
                        vector<int> vv{arr[i], arr[j], arr[l], arr[r]};
                        sort(vv.begin(), vv.end());
                        v.push_back(vv);
                        l++;
                        r--;
                    }
                    else if((arr[i]+arr[j]+arr[l]+arr[r]) < target)
                        l++;
                    else r--;
                }
            }
        }
        sort(v.begin(), v.end());
        vector<vector<int>>::iterator ip;
  
        // Using std::unique
        ip = std::unique(v.begin(), v.end());

        // Resizing the vector so as to remove the undefined terms
        v.resize(std::distance(v.begin(), ip));
        
        return v;
    }
};


//Leetcode
class Solution {
public:
    int addOvf(int a, int b, int c, int d) 
    { 
        long long result = (long long)a + (long long)b + (long long)c + (long long)d; 
        if(result > INT_MAX)
            return INT_MAX;
        return result; 
    }
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int> > v;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                while(l<r){
                    // cout<<arr[j]<<" "<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                    int sum = addOvf(arr[i], arr[j], arr[l], arr[r]); 
                    if(sum == INT_MAX){
                        l++;
                        r--;
                    } 
                    else if(sum == target){
                        vector<int> vv{arr[i], arr[j], arr[l], arr[r]};
                        sort(vv.begin(), vv.end());
                        v.push_back(vv);
                        l++;
                        r--;
                    }
                    else if(sum < target)
                        l++;
                    else r--;
                }
            }
        }
        sort(v.begin(), v.end());
        vector<vector<int>>::iterator ip;
  
        // Using std::unique
        ip = std::unique(v.begin(), v.end());

        // Resizing the vector so as to remove the undefined terms
        v.resize(std::distance(v.begin(), ip));
        
        return v;
    }
};