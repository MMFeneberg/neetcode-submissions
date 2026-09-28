class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size()) {
            return false;
        }
        std::unordered_map<char, int> stringS;
        std::unordered_map<char, int> stringT;
        for (int i = 0; i < t.size(); i++) {
            stringS[s[i]]++;
            stringT[t[i]]++;
        }
        for (char i = 'a'; i <= 'z'; i++) {
            if (stringS[i] != stringT[i]) {
                return false;
            }
        }
        return true;
    }
};
