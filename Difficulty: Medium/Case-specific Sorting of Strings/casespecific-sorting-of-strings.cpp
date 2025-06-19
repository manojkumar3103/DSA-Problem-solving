class Solution {
  public:
    string caseSort(string& s) {
        string lower, upper;

        for (char ch : s) {
            if (islower(ch))
                lower.push_back(ch);
            else if (isupper(ch))
                upper.push_back(ch);
        }

        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        int l = 0, u = 0;
        string ans;
    
        for (char ch : s) {
            if (islower(ch))
                ans.push_back(lower[l++]);
            else
                ans.push_back(upper[u++]);
        }
    
        return ans;
    }
};