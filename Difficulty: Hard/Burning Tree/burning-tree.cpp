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
    Node* start  = NULL ;
    void makeparent(unordered_map<Node* , Node*> &mp , Node* root , Node* parent, int t)
    {
        if(root == NULL ) return ;
        if(root->data == t ) start = root ;
        if(parent!=NULL) mp[root] = parent ;
        makeparent(mp , root->left  ,root ,t) ;
        makeparent(mp , root->right  ,root ,t ) ;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node* , Node*> mp ;
        makeparent(mp ,root ,NULL, target ) ;
        queue<Node*> q ;
        q.push(start) ;
        int level =  -1 ;
        unordered_set<Node*> st ;
        
        while(!q.empty())
        {
            
            int s = q.size() ;
            while(s--)
            {
                Node* u = q.front() ; q.pop() ;
                st.insert(u) ;
                if(mp.find(u)  != mp.end()  && st.find(mp[u]) == st.end()) q.push(mp[u]) ; // parent
                
                if(u->left != NULL && st.find(u->left) == st.end()) q.push(u->left) ;
                if(u->right!= NULL && st.find(u->right) == st.end()) q.push(u->right) ;
            }  
            level++ ;
        }
        return level ;
    }
};