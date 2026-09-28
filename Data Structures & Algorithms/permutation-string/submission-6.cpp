class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> string1(26,0);
        vector<int> string2(26,0);
        int total = 0;

        for (int i = 0; i < s1.size(); i++) {
            string1[s1[i] - 'a']++;
            total += (s1[i] - 'a' + 1);
        }

        int left = 0;

        int current = 0;

        for (int right = 0; right < s2.size(); right++) {
            current += (s2[right] - 'a' + 1);
            string2[s2[right] - 'a']++;
            if (current < total) {
                continue;
            } else if (current > total) {
                while (current > total) {
                    current -= (s2[left] - 'a' + 1);
                    string2[s2[left] - 'a']--;
                    left++;
                    if (total == current && string1 == string2) {
                        return true;
                    }
                }
            } else if (string1 == string2) {
                return true;
            }
            
        }
        return false;
        
    }
};
