//first check if that number is in its right position
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int> > v;
	    int n = nums.size(), ans = 0;
	    for(int i=0;i<n;i++){
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    vector<bool> visited(n);
	    
	    for(int i=0;i<n;i++){
	        if(visited[i] or v[i].second == i) //if it is right position
	            continue;
	        
	        int cycle_len=0;
	        int j=i;
	        while(visited[j] == false){
	            visited[j] = true;
	            cycle_len++;
	            j = v[j].second;
	        }
	        ans += cycle_len - 1;
	        
	    }
	    return ans;
	}
};