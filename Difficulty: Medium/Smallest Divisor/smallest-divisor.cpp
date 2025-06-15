class Solution {
public:
    int computeSum(vector<int>& arr, int divisor) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = computeSum(arr, mid);

            if (sum <= k) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return ans;
    }
};
