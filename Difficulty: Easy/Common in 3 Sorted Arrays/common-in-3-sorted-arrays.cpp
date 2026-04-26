class Solution {
  public:
    vector<int> commonElements(vector<int> &A, vector<int> &B, vector<int> &C) {
     int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < A.size() && j < B.size() && k < C.size()) {
        // If all elements are equal
        if (A[i] == B[j] && B[j] == C[k]) {
            // Avoid duplicates in result
            if (result.empty() || result.back() != A[i]) {
                result.push_back(A[i]);
            }
            i++; j++; k++;
        }
        // Move pointer with smallest value
        else if (A[i] < B[j]) {
            i++;
        }
        else if (B[j] < C[k]) {
            j++;
        }
        else {
            k++;
        }
    }

    return result;
    }
};