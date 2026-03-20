class Solution {
  public:
  vector<Node*> ans;
  
  void successor(Node* root , int key , Node* &s)
  {
      if(!root) return;

      if(root->data <= key)   // ✅ fixed
          successor(root->right , key , s);
      else
      {
          if(s == NULL || root->data < s->data)
              s = root;

          successor(root->left , key , s);
      }
  }

  Node* predecessor(Node* root , int key)
  {
      Node* ans = NULL;   // ✅ fixed
      
      while(root)
      {
          if(root->data < key)
          {
              ans = root;
              root = root->right;
          }
          else
          {
              root = root->left;
          }
      }
      return ans;
  }
  
  vector<Node*> findPreSuc(Node* root, int key) {

      Node* p = predecessor(root , key);
      ans.push_back(p);
      
      Node* s = NULL; 
      successor(root , key , s);
      ans.push_back(s);
      
      return ans;
  }
};