class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        if(arr[j][i]==1)
	        return j;
	    }
	}
    return -1;

	}

};


int rowWithMax1s(bool mat[R][C])
{
    int i, index;
 
    // Initialize max using values from first row.
    int max_row_index = 0;
    int max = first(mat[0], 0, C - 1);
 
    // Traverse for each row and count number of 1s
    // by finding the index of first 1
    for (i = 1; i < R; i++)
    {
        // Count 1s in this row only if this row
        // has more 1s than max so far
 
        // Count 1s in this row only if this row
        // has more 1s than max so far
        if (max != -1 && mat[i][C - max - 1] == 1)
        {
            // Note the optimization here also
            index = first (mat[i], 0, C - max);
 
            if (index != -1 && C - index > max)
            {
                max = C - index;
                max_row_index = i;
            }
        }
        else
        {
            max = first(mat[i], 0, C - 1);
        }
    }
    return max_row_index;
}
// O(m+n)