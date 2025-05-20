
class Solution {
  public:
    int peakElement(vector<int> &nums) {
       int left = 0;
    int right = nums.size() - 1;
    int ans = 0;  // To store peak index

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
            ans = left;  // update ans since slope is going up
        } else {
            right = mid;
            ans = right;  // update ans since slope is going down or peak at mid
        }
    }

    return ans;
    }
};
