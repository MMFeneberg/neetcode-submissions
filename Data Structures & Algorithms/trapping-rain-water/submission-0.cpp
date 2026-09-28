class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        vector<int> result(height.size(), 0);

        left[0] = 0;
        for (int i = 1; i < height.size(); ++i) {
            left[i] = max(left[i-1], height[i-1]);
        }

        right[height.size() - 1] = 0;
        for (int i = height.size() - 2; i > -1; --i) {
            right[i] = max(height[i+1], right[i+1]);
        }

        int total = 0;

        for (int i = 0; i < height.size(); ++i) { 
            result[i] = min(right[i], left[i]) - height[i];
            if (result[i] > 0) {
                total += result[i];
            }
        }


        return total;

    }
};
