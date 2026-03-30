class Solution {
  public:
  typedef pair<int , pair<int, int >> P ;
    vector<int> parent ;
    vector<int> rank ;
    int find (int i)
    {
        if(parent[i] == i ) return i; 
        return parent[i] = find(parent[i]) ;
        
    }
    void Union(int x , int y)
    {
        int parent_x = find(x) ;
        int parent_y = find(y) ;
        if(parent_x == parent_y ) return ;
        if(rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x ;
        }
        else if(rank[parent_x] < rank[parent_y])
        {
            parent[parent_x] = parent_y ;
        }
        else
        {
            parent[parent_x] = parent_y ;
            rank[parent_y]++ ; 
        }
    }
//   
    int minCost(vector<vector<int>>& h) {
        // code here
        int n= h.size() ;
        parent.resize(n) ;
        rank.resize(n , 0 ) ;
        for(int i=0;i<n;i++ ) parent[i] = i ;
        priority_queue<P , vector<P> ,greater<P> > pq ;
        for(int i=0;i<n-1;i++)
        {   
            for(int j =i+1 ;j<n;j++ )
            {
                int x1 = h[i][0] ; int x2 = h[j][0] ;
                int y1= h[i][1] ; int y2 = h[j][1] ;
                int dist = abs(x1 - x2 ) + abs(y1 - y2 ) ;
                pq.push({dist , { i , j}}) ; // value , {i , j } 
            }
            
        }
        int ans= 0 ;
        while(!pq.empty())
        {
            auto tops = pq.top() ;
            pq.pop() ;
            int w = tops.first ;
            int u = tops.second.first ;
            int v = tops.second.second ;
            int uparent =find(u) ;
            int qparent =find(v) ;
            if(uparent == qparent ) continue ;
            else{
                Union(u,v) ; ans += w ;
            }
        }
        return ans ;
    }
};