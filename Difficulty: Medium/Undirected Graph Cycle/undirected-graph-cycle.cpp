class Solution {
  public:
    bool dfs(unordered_map<int ,vector<int>>&mp , int u , int parent , vector<bool>& visited)
    {
        
        visited[u] = true ;
        for(auto v : mp[u])
        {   
            if(v==parent) continue;
            if(visited[v]) return true ;
            if(dfs(mp ,  v , u , visited)) return true; 
        }
        return false ;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int , vector<int>>mp ;
        for(auto it : edges)
        {
            int u = it[0] ;
            int v = it[1] ;
            mp[u].push_back(v) ;
            mp[v].push_back(u) ;
        }
            vector<bool> visited(V, false ) ;
        for(int i = 0 ; i < V ;i++)
        {   
            if(!visited[i] && dfs(mp , i,  -1 , visited)) return true ;
        }
        return  false ;
    }
};