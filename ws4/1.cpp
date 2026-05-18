#include <iostream>
#include <vector>


int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int main() {
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << lengthOfLIS(nums1);
}
