#include "iostream"
#include "vector"

int search_index(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    std::cout << search_index(nums, target) << std::endl;
    return 0;
}