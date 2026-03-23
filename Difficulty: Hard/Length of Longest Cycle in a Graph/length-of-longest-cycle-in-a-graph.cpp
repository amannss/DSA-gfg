class Solution {
  public:
  int ans =-1; 
  void solve(vector<int> &edge , int i , vector<int> & vis,vector<int> & path,int cnt )
  { 
      vis[i] = 1 ;
      path[i] = cnt ; 
      int next = edge[i] ;
      
      if(next != -1 )  // edge exist karti hai 
      {
          if(!vis[next])
          {
              solve(edge,next , vis, path, cnt + 1 ); // not a loop
          } 
          else if(path[next]!= -1 ) // in current loop
          {
              ans = max(ans , cnt - path[next]  + 1 ) ;
          }
      }
      path[i] = -1; 
      
      return ;
  }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> edge(V, -1);
        for (auto &it : edges)
        {
            edge[it[0]] = it[1];
        }
        vector<int> vis(V,  0) , path(V , -1) ;
        for(int i=0;i<V;i++)
        {
            if(!vis[i] ) solve(edge, i , vis , path , 1) ;
        }
        return ans;
    }
};
