class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<string, vector<string>> storage;

        for (string s : strs) {
            string key = "00000000000000000000000000";
            for (int i = 0; i < s.length(); i++) {
                key[s[i] - 'a']++;
            }


            auto it = storage.find(key);
            if (it != storage.end()) {
                storage[key].push_back(s);
            } else {
                storage[key].push_back(s);
            }
        }

        vector<vector<string>> result;
        int i = 0;

        for (auto it = storage.begin(); it != storage.end(); it++) {
            result.push_back(it->second);
        }
        return result;
        
    }
        
    
};
