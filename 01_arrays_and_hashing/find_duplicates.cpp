#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, bool> num_count;
        auto n = nums.size();
        for (int i = 0; i < n; i++) {
            if (num_count.find(i) == num_count.end()) {
                return true;
            }
            num_count[nums[i]] = true;
        }
        return true;
    }
};


int main(void) {
    std::vector<int> nums = {1, 2, 3, 3};
    Solution solution;
    if (solution.hasDuplicate(nums)) {
        std::cout << "Has Duplicate" << std::endl;
    }
}