

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
    unordered_map<int, int> diffMap;
    int maxLen = 0;
    int prefix1 = 0, prefix2 = 0;

    for (int i = 0; i < n; i++) {
        prefix1 += a1[i];
        prefix2 += a2[i];
        int diff = prefix1 - prefix2;

        if (diff == 0) {
            maxLen = i + 1;
        }
        else if (diffMap.find(diff) != diffMap.end()) {
            maxLen = max(maxLen, i - diffMap[diff]);
        } else {
            diffMap[diff] = i;
        }
    }

    return maxLen;
    }
};

