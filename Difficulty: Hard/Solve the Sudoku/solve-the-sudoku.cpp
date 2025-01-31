//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find a solved Sudoku.
    static void solveSudoku(vector<vector<int>>& mat) {
        solve(mat, 0, 0);
    }

private:
    static bool solve(vector<vector<int>>& mat, int i, int j) {
        if (i == 9) {
            return true;
        }
        int nextI = (j == 8) ? i + 1 : i;
        int nextJ = (j == 8) ? 0 : j + 1;

        if (mat[i][j] != 0) {
            return solve(mat, nextI, nextJ);
        }
        for (int val = 1; val <= 9; val++) {
            if (isValid(mat, i, j, val)) {
                mat[i][j] = val;
                if (solve(mat, nextI, nextJ)) {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }

    static bool isValid(vector<vector<int>>& mat, int r, int c, int val) {
        for (int i = 0; i < 9; i++) {
            if (mat[i][c] == val || mat[r][i] == val)
                return false;
        }

        int strR = (r / 3) * 3;
        int strC = (c / 3) * 3;
        for (int i = strR; i < strR + 3; i++) {
            for (int j = strC; j < strC + 3; j++) {
                if (mat[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};



//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends