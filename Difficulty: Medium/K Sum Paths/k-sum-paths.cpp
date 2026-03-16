/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int cnt = 0 ;
    void solve(unordered_map<int ,int> &mp , Node* root  , int k , int sum )
    {   
        if(root == NULL) return  ;
        int s  =sum+ root->data ;
        int rem = ( s- k) ;
        
        if(mp.find(rem) != mp.end()) cnt += mp[rem] ;
        mp[s]++ ;
        solve(mp ,root->left , k ,s ) ;
        solve(mp , root->right,k , s) ;
        mp[s]-- ;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int ,int > mp ;
        mp[0] = 1 ; 
        solve(mp , root , k , 0) ;
        return cnt ;
    }
};