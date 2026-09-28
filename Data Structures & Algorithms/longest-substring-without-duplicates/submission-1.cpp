class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_set<char> charSet;
        int total = 0;

        while (right < s.size()) {

            if (charSet.count(s[right])) {
                total = max(right - left, total);
                while (s[left] != s[right]) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.erase(s[left]);
                left++;
                charSet.insert(s[right]);

                right++;
            } else {
                charSet.insert(s[right]);
                right++;
            }
        }
        total = max(right - left, total);
        return total;
    }
};
