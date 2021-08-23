class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> u;
		    queue<char> q;
		    q.push(A[0]);
		    u[A[0]]++;
		    for(int i=1;i<A.length();i++){
		        u[A[i]]++;
		        if(u[A[i]] == 1)
		        q.push(A[i]);
		        
		        while(!q.empty()){
		            if(u[q.front()] == 1)
		            break;
		            q.pop();
		        }
		        if(q.empty())
		        A[i] = '#';
		        else
		        A[i] = q.front();
		        
		    }
		    return A;
		}

};