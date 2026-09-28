
class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        std::set<int> check;
        for (int i = 0; i < nums.size(); i++) {
            if (check.count(nums[i])){
                return true;
            } else {
                check.insert(nums[i]);
            }
        }
        return false;
    }
};
