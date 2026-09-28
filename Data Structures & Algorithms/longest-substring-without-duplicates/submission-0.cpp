class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> characters;

        int right = 0;
        int left = 0;

        int length = 0;

        for (; right < s.size(); right++) {
            if (characters.count(s[right])) {
                while (s[left] != s[right]) {
                    std::cout << "erased " << s[left] << "\n";
                    characters.erase(s[left]);
                    left++;
                }
                std::cout << "erased " << s[left] << "\n";
                characters.erase(s[left]);
                left++;

            }
                std::cout << "inserted " << s[right] << "\n";
                characters.insert(s[right]);
                length = max(length, right - left + 1);
            

        }
        return length;
    }
};
