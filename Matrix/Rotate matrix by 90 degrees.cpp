// transpose the matrix and then swap vectors 
// v[i] with v[n-1-i] till i<n/2
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            swap(arr[i][j], arr[j][i]);
	        }
	    }
	    
	    for(int i=0;i<n/2;i++){
	        swap(arr[i], arr[n-1-i]);
	    }
	}

};

void rotate90Clockwise(int a[N][N])
{
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}