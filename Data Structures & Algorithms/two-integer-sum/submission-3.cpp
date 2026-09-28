class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> answer;
        std::vector<int> arr;

        for (int i = 0; i < nums.size(); i++) {

            if (answer.count(target - nums[i])) {
                arr.push_back(answer[target - nums[i]]);
                arr.push_back(i);
                return arr;
            } else {
                answer[nums[i]] = i;
            }

            
        }
        return arr;
    }
};
