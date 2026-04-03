class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here

        int n = mat.size();
        vector<int> result;

        // Start from top row
        for(int col = 0; col < n; col++) {
            int i = 0, j = col;
            while(i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++; j--;
            }
        }

        // Start from last column (excluding first row)
        for(int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            while(i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++; j--;
            }
        }

        return result;
    }
};
