class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < t.size(); i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (map1[s[i]] != map2[s[i]]) {
                return false;
            }
        }
        return true;

    }
};
