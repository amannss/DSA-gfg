class Solution {
  public:



    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int , vector<int>> mp ;
        vector<int> result ;
        vector<int> indegree(V  , 0) ;
        for(auto it  : edges)
        {
            int u = it[0] ;int v = it[1] ;
            indegree[v]++ ;
            mp[u].push_back(v) ;
        }
        queue<int>q ;
        for(int i = 0;i <V ;i++) if(indegree[i] == 0 ) q.push(i) ;
        while(!q.empty() )
        {
            int u = q.front() ; q.pop() ;
            result.push_back(u) ;
            for(int v : mp[u])
            {
                indegree[v]-- ;
                if(indegree[v] == 0) q.push(v) ;
            }
        }
        return result ;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> result = topoSort(V , edges) ;
        if(result.size() ==  V ) return false  ;
        return true  ;
    }
};