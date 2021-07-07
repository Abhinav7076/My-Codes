class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> u;
		    char ch=A[0];
		    u[A[0]]++;
		    queue<char> q;
		    q.push(A[0]);
		    for(int i=1;i<A.size();i++){
		        u[A[i]]++;
		        
		        if(u[A[i]]==1)
		        q.push(A[i]);
		        
		        while(!q.empty()){
		            if(u[q.front()]==1)
		            break;
		            else
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