

class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1), prev(n, -1);
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                } else if (arr[i] % arr[j] == 0 && dp[j] + 1 == dp[i]) {
                    vector<int> currPath, newPath;
                    int idx = prev[i];
                    while (idx != -1) {
                        currPath.push_back(arr[idx]);
                        idx = prev[idx];
                    }
                    reverse(currPath.begin(), currPath.end());

                    idx = j;
                    while (idx != -1) {
                        newPath.push_back(arr[idx]);
                        idx = prev[idx];
                    }
                    reverse(newPath.begin(), newPath.end());

                    if (newPath > currPath) {
                        prev[i] = j;
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        vector<vector<int>> candidates;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                vector<int> subset;
                int idx = i;
                while (idx != -1) {
                    subset.push_back(arr[idx]);
                    idx = prev[idx];
                }
                reverse(subset.begin(), subset.end());
                candidates.push_back(subset);
            }
        }

        vector<int> result = candidates[0];
        for (const auto& c : candidates) {
            if (c > result) result = c;
        }

        return result;
    }
};
