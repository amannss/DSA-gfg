class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st ;
        for(auto it : a) st.insert(it) ;
        for(auto it : b) st.insert(it) ;
        vector<int> result ;
        for(auto it : st )
        {
            result.push_back(it) ;
        }
        return result ;
    }
};