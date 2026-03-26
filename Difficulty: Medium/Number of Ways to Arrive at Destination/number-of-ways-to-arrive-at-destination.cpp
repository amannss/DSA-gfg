class Solution {
  public:
  typedef pair<int,int> p ;
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        int mx = 1e7  ;
        vector<int> dist(V , mx ) ;
        dist[0] = 0 ;
        vector<int> path(V , 0 ) ;
        path[0]= 1 ;
        priority_queue<p,vector<p> , greater<p>> pq ;
        unordered_map<int, vector<p>> mp ;
        for(auto it : edges )
        {
            int u= it[0]; int v=it[1] ;int w = it[2] ;
            mp[u].push_back({v,w}) ;
            mp[v].push_back({u,w}) ;
        }
        pq.push({0,0}) ; // w , src
        while(!pq.empty())
        {
            auto  it = pq.top(); pq.pop() ;
            int u = it.second ;
            int w = it.first ;
            for(auto nghbr : mp[u])
            {
                int v = nghbr.first ;
                int d = nghbr.second ;
                if(w + d < dist[v])
                {
                    dist[v] = w + d ;
                    path[v] = path[u] ;
                    pq.push({d+w , v}) ;
                }
                else if(w + d == dist[v])
                {
                    path[v]+= path[u];
                }
            }
        }
        return path[V-1] ;
    }
};