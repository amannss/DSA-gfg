class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_map<int,int> mp ;
        vector<int> ans ;
        for(auto it : arr) mp[it]++ ;
        for(int i=low ;i<=high ;i++)
        {
            if(mp.find(i) == mp.end()) ans.push_back(i) ;
        }
        return ans ;
    }
};