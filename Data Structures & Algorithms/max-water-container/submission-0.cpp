class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size() -1;

        int maximum = 0;

        while (left < right) {
            maximum = max(maximum, (right - left) * min(heights[left], heights[right]));
        if (heights[left]<heights[right]) {
            left++;
        } else {
            right--;
        }
        }
        return maximum;
    }
};
