class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int result = 0;
        int leftMax = height[left];
        int rightMax = height[right];

        while (left != right) {
            if (height[left] > height[right]) {
                right--;
                if (rightMax <= height[right]) {
                    rightMax = height[right];
                } else {
                    result += (min(rightMax, leftMax) - height[right]);
                }
            } else {
                left++;
                if (leftMax <= height[left]) {
                    leftMax = height[left];
                } else {
                    result += (min(leftMax, rightMax) - height[left]);
                }
            } 
        }
        return result;

    }
};
