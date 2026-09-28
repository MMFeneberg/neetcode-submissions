class Solution {
public:
    string reorganizeString(string s) {
        vector<int> letters(26,0);
        priority_queue<pair<int, char>> pq;
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            letters[s[i] - 'a']++;
        }

        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > 0) {
                pq.push(make_pair(letters[i], i + 'a'));
            }
        }

        pair<int, char> prev;
        pair<int, char> temp;
                

        while (!pq.empty()) {
            cout << pq.top().first << ", " << pq.top().second << "\n";
            prev = pq.top();
            pq.pop();
            if (temp.first > 0) {
                pq.push(temp);
            }
            result.push_back(prev.second);
            prev.first--;
            if (prev.first == 0) {
                temp = prev;
                continue;
            } else {
                temp = prev;
                if (pq.empty() && temp.first > 0) {
                    return "";
                }
            }
        }
        return result;
        
    }
};