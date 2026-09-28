class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> dest;
        dest.resize(position.size());
        unordered_map<int, int> posToSpeed;
        int result = 0;
        for (int i = 0; i < position.size(); i++) {
            posToSpeed[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        for (int i = 0; i < position.size(); i++) {
            cout << "pos: " << position[i] << "\n";
            dest[i] = (target - position[i]) / ((double) posToSpeed[position[i]]);
            cout << "dest: "<< dest[i] << "\n";
        }
        unordered_set<double> results;
        reverse(dest.begin(), dest.end());
        double mini = INT_MIN;
        for (int i = 0; i < position.size(); i++) {
            if (dest[i] <= mini) {
                dest[i] = mini;
                cout << mini << "\n";
            } else {
                mini = dest[i];
                cout << mini << "\n";
            }
            results.insert(dest[i]);
        }
        return results.size();
    }
};
