class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        unordered_map<int ,vector<int>> mp ;
        vector<int> indegree(n , 0 ) ;
        for(auto it : prerequisites)
        {
            int x = it[1] ;
            int y = it[0] ;
            mp[x].push_back(y) ;
            indegree[y]++ ;
        }
        vector<int> result ;
        queue<int> q ;
        for(int i = 0 ;i <n;i++) if(indegree[i] == 0 ) q.push(i) ;
        while(!q.empty())
        {
            int u = q.front() ;
            q.pop() ;
            result.push_back(u) ;
            for(auto v : mp[u])
            {
                indegree[v]-- ;
                if(indegree[v] == 0 ) q.push(v) ;
            }
        }
        return result.size() == n ;
    }
};