class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
};