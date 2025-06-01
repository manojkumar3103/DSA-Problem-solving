

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[mat2[i][j]]++;
            }
        }
    
        int count = 0;
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int complement = x - mat1[i][j];
                if (freq.find(complement) != freq.end()) {
                    count += freq[complement];
                }
            }
        }
    
        return count;
    }
};

