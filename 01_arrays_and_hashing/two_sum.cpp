#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<long, int> num_idx;
        auto n = nums.size();

        for (int i = 0; i < n; i++) {
            long complement = target - nums[i];
            if (num_idx.find(complement) != num_idx.end()) {
                std::vector<int> res;
                int j = num_idx[complement];
                if (i < j) {
                    res = {i, j};
                } else {
                    res = {j, i};
                }
                return res;
            }

            //add number to hash
            if (num_idx.find(nums[i]) == num_idx.end()) {
                num_idx[nums[i]] = 0;
            }
            num_idx[nums[i]] += 1;
        }
        //unreachable
        return {};
    }
};

int main() {
    std::vector<int> nums = {1, 2, 5, 9};
    Solution solution;
    std::vector<int> s = solution.twoSum(nums, 7);
    std::cout << "The answer is: " << s[0] << " and " << s[1] << std::endl;
}