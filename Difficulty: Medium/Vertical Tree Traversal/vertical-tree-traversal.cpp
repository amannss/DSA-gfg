/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
typedef pair<Node*, pair<int, int>> p ;
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<pair<Node* , pair<int,int>>> q ;
        q.push({root , { 0 , 0}}) ; // data , V , level 
        map<int ,map< int , vector<int>>> mp ; // V -> { L -> set } 
        while(!q.empty())
        {
            p top = q.front() ;
            q.pop() ;
             
            Node* node  = top.first  ;
            int V = top.second.first;
            int L = top.second.second ;
            mp[V][L].push_back(node->data);
            if(node->left)
            {   
                q.push({node->left,{V-1 , L+1 }}) ;
            }   
            if(node->right)
            {   
                q.push({node->right,{V+1 , L+1}}) ;
            }
        }
        vector<vector<int>> vec ;
        for(auto it : mp)
{
    vector<int> temp;
    
    for(auto u : it.second)
    {   
        vector<int> &sk = u.second;
        temp.insert(temp.end(), sk.begin(), sk.end());
    }
    
    vec.push_back(temp);
}
        return vec ;
        
    }
};