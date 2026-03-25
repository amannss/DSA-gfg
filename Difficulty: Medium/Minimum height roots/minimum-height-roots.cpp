class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int> indegree(V, 0 ) ;
        unordered_map<int ,vector<int>> mp ;
        for(auto it : edges)
        {
            int u = it[0] ;int v= it[1] ;
            mp[u].push_back(v) ;
            mp[v].push_back(u) ;
            indegree[u]++ ;
            indegree[v]++ ;
        }
        queue<int> q ;
        for(int i=0;i<V;i++ ) if(indegree[i] == 1) q.push(i) ;
        int n = V ;
        while(n>2)
        {
            
            int size  = q.size() ;
            
            while(size--)
            {
                int u = q.front() ;
                q.pop() ;n--;
                for(auto v : mp[u])
                {
                    indegree[v]-- ;
                    if(indegree[v]== 1) q.push(v); 
                }
                
            }
        }
        vector<int> ans ;
        while(!q.empty()) {
            int tops = q.front() ;q.pop() ;
            ans.push_back(tops) ;
        }
        return ans ;
    }
};