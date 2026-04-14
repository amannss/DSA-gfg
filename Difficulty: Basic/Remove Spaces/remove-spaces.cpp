class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string t = "" ;
        for(auto c : s)
        {
            if(c!= ' ')
            t.push_back(c) ;
        }
        return t ;
    }
};