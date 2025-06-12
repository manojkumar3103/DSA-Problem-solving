class Solution {
  public:
  
  struct compare {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;  
            return a.first < b.first;       
        }
    };
    vector<int> printKClosest(vector<int> arr, int k, int x) {

        vector<pair<int, int>> candidates;

        for (int num : arr) {
            if (num == x) continue;
            candidates.push_back({abs(num - x), -num}); 
        }

        sort(candidates.begin(), candidates.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(-candidates[i].second); 
        }

        return result;
    }
};