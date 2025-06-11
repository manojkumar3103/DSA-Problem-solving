

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size(), l = 0, r = n - 1, i = A >= 0 ? n - 1 : 0;
        vector<int> res(n);
        auto f = [&](int x) { return A * x * x + B * x + C; };
        while (l <= r) {
            int lv = f(arr[l]), rv = f(arr[r]);
            if (A >= 0) res[i--] = lv > rv ? lv : rv, lv > rv ? ++l : --r;
            else res[i++] = lv < rv ? lv : rv, lv < rv ? ++l : --r;
        }
        return res;
    }
};

