class Solution {
public:
    bool isPalindrome(string s) {
        int d = s.size() -1;
        for (int i = 0; i < s.size()/2; i++) {
            while (d != i && !isalnum(s[i])) {
                i++;
            }
            while (d != i && !isalnum(s[d])) {
                d--;
            }
            if (tolower(s[i]) != tolower(s[d])) {
                return false;
            } 
            d--;
        }
        return true;
    }
};
