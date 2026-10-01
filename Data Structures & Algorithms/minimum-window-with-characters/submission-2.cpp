class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char,int> tMap;


        for (char c : t) {
            tMap[c]++;
        }

        int req = tMap.size();


        unordered_map<char,int> current;
        int size = INT_MAX;
        int leftResult = -1;

        int left = 0;
        int right = 0;

        int have = 0;

        while (right < s.size()) {
            current[s[right]]++;

            if (tMap.count(s[right]) && current[s[right]] == tMap[s[right]]) {
                have++;
            }
            while (have == req) {
                if (size > right - left + 1) {
                    size = right - left + 1;
                    leftResult = left;
                }
                current[s[left]]--;
                if (tMap.count(s[left])&& current[s[left]] < tMap[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }

        if (leftResult == -1) {
            return "";
        }

        return s.substr(leftResult,size);


    }
};
