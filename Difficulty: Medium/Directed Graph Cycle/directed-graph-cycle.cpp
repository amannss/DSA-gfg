class Solution {
  public:
    bool dfs(unordered_map<int ,vector<int>>&mp , int u,vector<bool>&visited ,vector<bool>&inreccursion)
    {
        visited[u] = true ;
        inreccursion[u] = true; 
        for(auto v : mp[u])
        {
            if(visited[v] && inreccursion[v]) return true ;
            else if(visited[v]) continue ;
            
            if(dfs(mp ,v , visited, inreccursion)) return true  ;
        }
        inreccursion[u] = false ;
        return false ;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int , vector<int>> mp ;
        for(auto it : edges)
        {
            int u = it[0] ; int v = it[1] ;
            mp[u].push_back(v) ;
        }
        vector<bool>visited(V ,false ) , inreccursion(V , false ) ;
        for(int i =0;i<V ;i++)
        {
            if(!visited[i] && dfs(mp ,i ,visited,inreccursion)) return true ;
        }
        return false; 
    }
};