class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> days;
        stack<int> index;
        vector<int> result;
        result.resize(temperatures.size());
        result[result.size()-1] = 0;
        int last = 0;
        
        for (int i = 0 ; i < temperatures.size() - 1; i++) {
            days.push(temperatures[i]);
            index.push(i);
            if (temperatures[i] >= temperatures[i+1]) {
                continue;
            } else {
                last = temperatures[i+1];
                while (!days.empty() && last > days.top()) {
                    result[index.top()] = (i+1) - index.top();
                    index.pop();
                    days.pop();
                }
            }
        }
        return result;
    }
};
