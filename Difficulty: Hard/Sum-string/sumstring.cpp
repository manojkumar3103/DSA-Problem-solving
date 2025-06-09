

class Solution {
  public:
  
  string addStrings(const string &a, const string &b) {
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.insert(result.begin(), sum % 10 + '0');
        carry = sum / 10;
    }

    return result;
}
bool isSumRecursive(const string &s, string a, string b, int start) {
    string sum = addStrings(a, b);
    int len = sum.size();

    if (start + len > s.size() || s.substr(start, len) != sum)
        return false;

    if (start + len == s.size())
        return true;

    return isSumRecursive(s, b, sum, start + len);
}

bool isSumString( string &s) {
    int n = s.size();

    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= (n - i) / 2; ++j) {
            string a = s.substr(0, i), b = s.substr(i, j);

            // Skip if invalid due to leading zeros
            if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0'))
                continue;

            if (isSumRecursive(s, a, b, i + j))
                return true;
        }
    }

    return false;
}

};

