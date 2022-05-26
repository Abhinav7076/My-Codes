class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        Node* result = new Node();
        addNode(node, result);
        
        return result;
    }
    
    void addNode(Node* oldNode, Node* newNode)
    {
        newNode->val = oldNode->val;
        visited[newNode->val] = newNode;
        
        for (Node *node : oldNode->neighbors)
        {
            auto it = visited.find(node->val);
            if (it != visited.end())
            {
                newNode->neighbors.push_back(it->second);
            }else
            {
                newNode->neighbors.push_back(new Node());
                addNode(node, newNode->neighbors.back());
            }
        }
    }
    
    std::map<int, Node*> visited;
};