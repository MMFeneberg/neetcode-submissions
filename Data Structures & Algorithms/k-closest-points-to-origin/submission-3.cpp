class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<double, vector<int>> indices;
        priority_queue<double,vector<double>> minHeap;
        
        for (int i = 0; i < k; i++) {
            double d = distance(points[i]);
            minHeap.push(d);
            indices[d].push_back(i);
        }
        for (int i = k; i < points.size(); i++) {
            double d = distance(points[i]);
            cout << minHeap.top() << ", " << d << "\n";
            if (d < minHeap.top()) {
                minHeap.push(d);
                indices[d].push_back(i);
                d = minHeap.top();
                indices[d].pop_back();
                minHeap.pop();
            }
        }
        vector<vector<int>> result;

        for (auto& index: indices) {
            for (int i = 0; i < index.second.size(); i++) {
                result.push_back(points[index.second[i]]);
            }
        }
        return result;
    }

    double distance (vector<int>& point) {
        return sqrt((pow(0-point[0],2)) + (pow(0-point[1],2)));
    }
};
