#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <array>

struct ArrayHasher {
    std::size_t operator()(const std::array<int, 26>&a) const {
        std::size_t h = 0;
        for (auto e: a) {
            h ^= std::hash<int> {}(e) + 0x9e377b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
};

std::vector<std::vector<std::string>> Solution::groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHasher> anagram_map;
    for (auto s: strs) {

        //create count array for key
        std::array<int, 26> count_array = {0};
        for(auto c: s) {
            count_array[c - 'a'] += 1;
        }

        if (anagram_map.find(count_array) == anagram_map.end()) {
            anagram_map[count_array] = {};
        }

        anagram_map[count_array].push_back(s);
    }

    int i = 0;
    std::vector<std::vector<std::string>> res;
    for (auto& x: anagram_map) {
        res.push_back({});
        for (auto v: anagram_map[x.first]) {
            res[i].push_back(v);
        }
        i++;
    }

    return res;
}

int main() {
    std::vector<std::string> strs = {"abc", "bca", "cars", "racs", "white"};
    Solution solution;
    auto sol = solution.groupAnagrams(strs);

    int count = 0;
    for(auto x: sol) {
        std::cout << "anagram group " << count << ": ";
        for (auto s: x) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
        count += 1;
    }
}