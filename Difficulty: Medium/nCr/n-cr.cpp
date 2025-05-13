//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fact(int n)
    {
        int ans=n;
        for(int i=n-1;i>0;i--)
            ans*=i;
        return ans;
    }
    int nCr(int n, int r) {
        // code here
        if(r>n) return 0;
        if (r == 0 || r == n) return 1;
        r=min(r, n - r); // Use symmetry
        long long int res = 1;

        for (int i = 1; i <= r; ++i) {
            res *= (n - r + i);
            res /= i;
        }
        return (int)res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends