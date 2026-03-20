/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
#define  mx INT_MAX
#define mn INT_MIN
    vector<int> vec ;
    vector<int>  solve(int &ans , Node * root  )
    {
        if(root == NULL ) return {0 ,mn ,mx} ;
        vector<int> left = solve(ans , root ->left );
        vector<int> right= solve(ans , root -> right ) ;
        if(left[1] < root->data && right[2] > root->data)
        {   
            ans = max(ans , left[0]  + right[0] + 1) ;
            return {left[0] + right[0] + 1, max(root->data, right[1]) , min(root->data , left[2]) } ;
        }
        else return {max(left[0] , right[0]) ,mx , mn } ;
    }
    int largestBst(Node *root) {
        int ans = 0 ;
        solve(ans , root ) ;
        return ans ;
        
    }
};