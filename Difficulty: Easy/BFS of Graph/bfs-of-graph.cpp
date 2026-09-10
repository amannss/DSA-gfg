class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q ;
        int n = adj.size() ;
        vector<bool> visited(n , false ) ;
        q.push(0) ;
        visited[0] = true ;
        vector<int> result ;
        result.push_back(0) ;
        while(!q.empty())
        {
            int u = q.front() ; q.pop() ;
            for(auto v : adj[u])
            {
                if(!visited[v])
                {   
                    result.push_back(v) ;
                    visited[v] = true ;
                    q.push(v) ;
                }
            }
        }
        return result ;
    }
};