class Solution {
  public:
    vector<vector<int>> directions{{0,1 } , { 1,0} ,{ -1 , 0 } ,{0,-1}} ;
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int m = mat.size() ; int n = mat[0].size() ;
        queue<pair<int ,int>> q ;
        int fresh = 0 ;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 2) q.push({i , j}) ;
                if(mat[i][j]== 1) fresh++ ;
            }
        }
        if(fresh == 0) return 0 ;
        int minutes = 0 ; 
        while(!q.empty())
        {
            int size = q.size() ;
            bool marked_this_time  = false ;
            for(int k= 1 ;k <=size ;k++)
            {
                auto tops = q.front() ;q.pop() ;
                int i=tops.first ; int j = tops.second ;
                for(auto it : directions )
                {
                    int new_i = i + it[0] ;
                    int new_j = j + it[1] ;
                if(new_i >= 0 && new_j >=0 && new_i < m && new_j < n && mat[new_i][new_j]==1)
                {
                    mat[new_i][new_j]= 2  ; // mark rotted 
                    q.push({new_i , new_j}) ;
                    marked_this_time = true ;
                    fresh-- ;
                }
                }
            }
            if(marked_this_time ) minutes++ ;
        }
        return fresh==0 ? minutes : -1 ;
    }
};