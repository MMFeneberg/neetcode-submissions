#include <set>;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        std::set<int> check;
        for (int i = 0; i < nums.size(); i++) {
            check.insert(nums[i]);
        }
        return check.size() != nums.size();
    }
};
