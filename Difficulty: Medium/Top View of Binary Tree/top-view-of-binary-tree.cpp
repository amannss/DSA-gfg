/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int ,map<int , vector<int>>> mp ;
        queue<pair<Node* , pair<int ,int>>> q ;
        q.push({root , {0,0}}) ;
        while(!q.empty())
        {
            pair<Node* , pair<int ,int>> x = q.front() ; q.pop() ;
            Node* r = x.first ;
            int v = x.second.first ;
            int l = x.second.second;
            mp[v][l].push_back(r->data) ;
            if(r -> left )
            {
                q.push({r->left ,{v-1 , l+1}}); 
            }
            if(r -> right)
            {
                q.push({r->right ,{v+1 , l+1}}) ;
            }
        }
        vector<int> result ;
        for(auto it : mp)
        {   
            
            map<int , vector<int>> p = it.second ;
            int smallestlevel = p.begin()->first ;
            int value = p[smallestlevel].front() ;
            result.push_back(value) ;
        }
        return result ;
    }
};