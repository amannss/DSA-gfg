class Solution {
  public:
    vector<int> result ;
    void dfs(unordered_map<int , vector<int>>& mp ,vector<bool>&visited , int u  )
    {
        if(visited[u]) return ;
        visited[u] = true ;
        result.push_back(u) ;
        for(auto v : mp[u])
        {
            if(!visited[v])
            {
                dfs(mp , visited , v) ;
            }
        }
        return  ; 
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int , vector<int>> mp; 
        int n = adj.size() ;
        for(int i = 0 ; i < n;i++)
        {
            mp[i] = adj[i] ;
        }
        vector<bool> visited(n , false ) ;
        dfs(mp , visited , 0) ;
        return result ;
    }
};