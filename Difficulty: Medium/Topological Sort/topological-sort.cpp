class Solution {
  public:
    void dfs(unordered_map<int,vector<int>>&mp,vector<int>&result , int u , vector<bool>&visited ,stack<int>& st )
    {
        visited[u] = true ;
        for(auto v : mp[u])
        {
            if(!visited[v])
            {
                dfs(mp,result ,v, visited, st) ;
            }
        }
        st.push(u) ;
        return ;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> result ;
        unordered_map<int ,vector<int>> mp ;
        for(auto it : edges)
        {
            int u = it[0] ;int v = it[1] ;
            mp[u].push_back(v) ;
        }
        vector<bool> visited(V , false) ;
        stack<int> st ; 
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i] )
            {   
                dfs(mp , result ,i , visited ,st ) ;
            }
        }
        while(!st.empty())
        {
            int u = st.top() ; st.pop() ;
            result.push_back(u);
        }
        return result ;
    }
};