#include <vector>
#include <unordered_map>
#include <iostream>
#include <array>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        //bucket sort, bin sort, whatever you call it
        
        //step 1. create count hash map
        std::unordered_map<int, int> count;
        for (auto n: nums) {
            if (count.find(n) == count.end()) {
                count[n] = 0;
            }
            count[n] += 1;
        }

        //step 2. create array of vector pointers?
        int size = nums.size();
        std::vector<int> bucket[size + 1];
        for (auto& x: count) {
            //key:value = number:count
            bucket[x.second].push_back(x.first);
        }

        //top k
        std::vector<int> res;
        int t = 0;
        for(int i = size; i > -1; i--) {
            for (auto n: bucket[i]) {
                if (t == k) {return res;}
                res.push_back(n);
                t += 1;
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 7, 7};
    Solution solution;
    std::vector<int> sol = solution.topKFrequent(nums, 2);
    std::cout << "top 2 frequent: ";
    for (auto n: sol) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}