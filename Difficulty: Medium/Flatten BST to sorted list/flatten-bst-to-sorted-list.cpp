/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node *flattenBST(Node *root) {
        // code here
        if(!root) return NULL ;
        Node* lefthead = flattenBST(root->left) ;
        Node* temp = lefthead ;
        root->left = NULL ;
        while(temp!=NULL && temp->right !=NULL)
        {
            temp= temp->right ;
        }
        Node* righthead = flattenBST(root->right) ;
        if(temp!=NULL) temp->right = root ;
        root->right = righthead ;
        if(!lefthead) return root ;
        else return lefthead ;
    }
};