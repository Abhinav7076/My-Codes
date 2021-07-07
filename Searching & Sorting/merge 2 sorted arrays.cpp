//without using extra space
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=n-1, j=0;
	    while(i>=0 and j<m){
	        if(arr1[i] > arr2[j]){
	            swap(arr1[i], arr2[j]);
	            i--;
	            j++;
	        }
	        else
	        break;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};

//with using extra space
vector<int> merge_vec(vector<int> &a, vector<int> &b, int n, int m) {
    // code here
    vector<int> v;
    int i=0,j=0;
    while(i<n and j<m){
        if(a[i] > b[j]){
            v.push_back(b[j]);
            j++;
        }
        else{
            v.push_back(a[i]);
            i++;
        }
    }
    while(i<n){
        v.push_back(a[i++]);
    }
    while(j<m){
        v.push_back(b[j++]);
    }
    
    return v;
}