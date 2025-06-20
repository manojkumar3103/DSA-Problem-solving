class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n % k != 0) return false;
    
        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
    
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;
            if (count > 0) {
                for (int i = 0; i < k; ++i) {
                    int curr = num + i;
                    if (freq[curr] < count) {
                        return false; 
                    }
                    freq[curr] -= count;
                }
            }
        }
        return true;
    }
};