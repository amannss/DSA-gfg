class Solution {
  public:
  vector<string > result ; 
  int n ;
  
 
  void backtrack(string s , string curr  ,int i, int parts)
  {
      if(i>=n && parts == 4)
      {
          curr.pop_back() ;
          result.push_back(curr) ;
          return ;
      }
      // 
      if(parts >= 4 || i >= n) return ;
      for(int len = 1  ; len <= 3 && len + i <= n;len++)
      {
          string sub = s.substr(i , len) ;
          if((sub.size() > 1 &&  sub[0] == '0' ) || stoi(sub) > 255 ) continue ;
        backtrack(s ,curr +sub+'.' , i + len ,parts + 1) ;
      }
      return ;
  }
    vector<string> generateIp(string &s) {
        // code here
        n = s.length() ;
        if(n < 4 || n > 12 ) return result ;
        
        backtrack(s , ""  , 0 , 0) ;
        return result ;
    }
};