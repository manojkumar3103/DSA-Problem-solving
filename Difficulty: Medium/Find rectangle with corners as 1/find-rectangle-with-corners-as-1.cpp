class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int rows = mat.size();
        if (rows == 0) return false;
        int cols = mat[0].size();
    
        unordered_set<string> seenPairs;
    
        for (int i = 0; i < rows; ++i) {
        
            vector<int> ones;
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    ones.push_back(j);
                }
            }
    
            for (size_t p = 0; p < ones.size(); ++p) {
                for (size_t q = p + 1; q < ones.size(); ++q) {
                    int c1 = ones[p], c2 = ones[q];
                    string key = to_string(c1) + "," + to_string(c2);
                    if (seenPairs.find(key) != seenPairs.end()) {
                        return true; 
                    }
                    seenPairs.insert(key);
                }
            }
        }
    
        return false;
        
    }
};