vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> v;
	if(!root) return v;
	queue<Node*> q;
	
	q.push(root);
	int f=1;
	while(!q.empty()){
	    vector<int> temp;
	    int size = q.size();
	    while(size--){
	        
    	    Node* t = q.front();
	        temp.push_back(t->data);
	        q.pop();
	        if(t->left)
	        q.push(t->left);
	        if(t->right)
	        q.push(t->right);
	    }
	    if(f%2==0)
	        reverse(temp.begin(), temp.end());
	       
	    for(int i=0;i<temp.size();i++)
	        v.push_back(temp[i]);
	        
	    f=!f;
	    
	    
	}
	return v;
}

//time complexity = O(n) , since we are going through every node once