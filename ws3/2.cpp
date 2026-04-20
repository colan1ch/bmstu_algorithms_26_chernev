#include <iostream>
#include <queue>


int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue< int, std::vector<int>, std::greater<int> > pq;
    for (int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << findKthLargest(nums, 3);

    return 0;
}
