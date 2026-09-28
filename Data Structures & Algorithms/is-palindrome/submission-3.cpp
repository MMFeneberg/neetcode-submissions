class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.length() - 1;

        while (right > left) {
            while (!isalnum(s[left])) {
                
            
            if (!isalnum(s[left])) {
                left++;
            }
            }
            while (!isalnum(s[right])) {
            if (!isalnum(s[right])) {
                right--;
            }
            }
            if (toupper(s[left]) != toupper(s[right]) && left < right) {
                std::cout << s[left] << ", " << s[right] << "\n";
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
