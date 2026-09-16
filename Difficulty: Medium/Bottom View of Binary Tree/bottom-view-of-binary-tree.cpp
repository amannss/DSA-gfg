/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  unordered_map<Node* , int> index ;
  map<int , int> mp ;
  vector<int> result ;
  void solve(Node* root , int n )
  {
      if(!root) return  ;
      index[root] = n ;
      solve(root->left , n-1) ;
      solve(root->right , n + 1) ;
      return ;
  }
  void get(Node* root)
  {
      queue<Node*> q ;
      q.push(root) ;
      while(!q.empty())
      {
          Node* r = q.front() ;
          q.pop() ;
          int v = index[r] ;
          mp[v] = r->data ;
          if(r->left) q.push(r->left) ;
          if(r->right) q.push(r->right) ;
      }
  }
    vector<int> bottomView(Node *root) {
        // code here
        if(!root) return {} ;
        solve(root , 0 ) ;
        get(root) ;
        for(auto it : mp) result.push_back(it.second) ;
        return result ;
    }
};