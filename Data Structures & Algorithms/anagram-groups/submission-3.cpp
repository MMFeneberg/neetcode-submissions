class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        unordered_map<string, vector<string>> solution;

        for (int i = 0; i < size; i++) {
            vector<int> code(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                code[strs[i][j] - 'a' ]++;
            }
            string key;
            for (int j = 0; j < 26; j++) {
                key += to_string(code[j]);
                key+= '-';
            }
            solution[key].push_back(strs[i]);
        }

        vector<vector<string>> answer;

        for (auto vec : solution) {
            answer.push_back(vec.second);
        }

        return answer;

    }
};
