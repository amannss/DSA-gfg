class Solution {
  public:
    
    void solve(int n, vector<string>& result) {
        if (n == 0) {
            result.push_back("");
            return;
        }
        
        solve(n - 1, result);
        
        int size = result.size();
        
        // add '0' to first half
        for (int i = 0; i < size; i++) {
            result[i] = "0" + result[i];
        }
        
        // add reversed '1' part
        for (int i = size - 1; i >= 0; i--) {
            result.push_back("1" + result[i].substr(1));
        }
    }
    
    vector<string> graycode(int n) {
        vector<string> result;
        solve(n, result);
        return result;
    }
};