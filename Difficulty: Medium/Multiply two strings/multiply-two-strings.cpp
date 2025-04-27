//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
    // Step 1: Handle sign
    bool isNegative = false;
    if (num1[0] == '-') {
        isNegative = !isNegative;
        num1 = num1.substr(1);  // Remove negative sign
    }
    if (num2[0] == '-') {
        isNegative = !isNegative;
        num2 = num2.substr(1);  // Remove negative sign
    }

    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);

    // Step 2: Multiply each digit
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Step 3: Build result string
    string ans = "";
    bool leadingZero = true;
    for (int num : result) {
        if (leadingZero && num == 0) continue;
        leadingZero = false;
        ans += (num + '0');
    }

    if (ans.empty()) return "0";

    if (isNegative) ans = "-" + ans;

    return ans;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends