class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        result[1] = nums[0];
        std::cout << result[1] << "\n";


        for (int i = 1; i < nums.size(); i++) {
            result[i] = nums[i - 1] * result[i - 1];
            std::cout << result[i] << "\n";
        }


        int product = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= product;
            product *= nums[i];
        }

        return result;
    }
};
