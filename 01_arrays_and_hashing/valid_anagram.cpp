#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        //base case
        if (s.length() != t.length()) {return false;}
        std::unordered_map<char, int> chars_s;
        std::unordered_map<char, int> chars_t;
        auto n = s.length();

        for (int i = 0; i < n; i++) {
            //complete hash map
            if (chars_s.find(s[i]) == chars_s.end()) {
                chars_s[s[i]] = 0;
            }
            if (chars_t.find(t[i]) == chars_t.end()) {
                chars_t[t[i]] = 0;
            }
            chars_s[s[i]] += 1;
            chars_t[t[i]] += 1;
        }

        return chars_s == chars_t;
    }
};

int main() {
    std::string s = "hello";
    std::string t = "olleh";
    Solution solution;
    std::cout << solution.isAnagram(s, t) << std::endl;
}