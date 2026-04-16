class Solution {
  public:
    string URLify(string &s) {
        // code here
        string temp = "" ; 
        int n = s.length() ;
        for(int i=0;i<n  ; i++)
        {
            if(s[i] == ' ')
            {
                temp += "%20" ;
            }
            else temp.push_back(s[i]) ;
        }
        return temp ;
    }
};