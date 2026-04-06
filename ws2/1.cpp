#include <iostream>
#include <string>
#include <vector>


int lengthOfLongestSubstring(std::string s) {
    std::vector<int> last_ind(256, -1);
    int max_len = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (last_ind[s[end]] >= start) {
            start = last_ind[s[end]] + 1;
        }
        last_ind[s[end]] = end;
        max_len = std::max(max_len, end - start + 1);
    }
    return max_len;
}


int main() {
    std::string s = "abcabcbb";
    std::cout << "Answer: " << lengthOfLongestSubstring(s) << '\n';
    s = "bbbbb";
    std::cout << "Answer: " << lengthOfLongestSubstring(s) << '\n';
    s = "pwwkew";
    std::cout << "Answer: " << lengthOfLongestSubstring(s) << '\n';
    return 0;
}
