class Solution {
  public:
    int atMostKDistinct(const string& s, int k) {
        int left = 0, count = 0, distinct = 0;
        vector<int> freq(26, 0);
    
        for (int right = 0; right < s.size(); ++right) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;
    
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }
    
            count += (right - left + 1);
        }
    
        return count;
}
    int countSubstr(string& s, int k) {
         return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
};