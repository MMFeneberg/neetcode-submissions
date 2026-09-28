class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i]) && !isalnum(s[j])) {
                j--;
                continue;
            }
            else if (!isalnum(s[i])) {
                continue;
            } else if (!isalnum(s[j])) {
                j--;
                i--;
            } else if (toupper(s[i]) != toupper(s[j])) {
                cout << s[i] << ' ' << s[j];
                return false;
            } else {
                j--;
            }
        }
        return true;
    }
};
