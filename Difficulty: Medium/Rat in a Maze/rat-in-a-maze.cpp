class Solution {
  public:
  vector<string> result ;
  vector<pair<char, pair<int,int>>> directions = {
    {'D',{1,0}},
    {'L',{0,-1}},
    {'R',{0,1}},
    {'U',{-1,0}}
};
  
    void solve(vector<vector<int>>&maze ,int n,int i ,int j , string ans )
    {
        if(i<0 || j< 0 || i>=n || j>= n || maze[i][j] == 0) return ;
        if(i>= n-1 && j>=n-1)
        {
            result.push_back(ans) ;
            return ;
        }
        
        maze[i][j]  = 0  ;
        for(auto it : directions)
        {
            char c = it.first ;
            int newi = i + it.second.first ;
            int newj = j + it.second.second; 
            ans.push_back(c) ;
            solve(maze ,n ,newi, newj, ans ) ;
            ans.pop_back();
        }
        maze[i][j] = 1 ;
        return ;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size() ;
        
        solve(maze , n ,0 , 0 ,"" ) ;
        return result ;
        
    }
};