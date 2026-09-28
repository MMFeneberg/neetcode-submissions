class KthLargest {
public:
    priority_queue<int> maxHeap;
    int element;
    KthLargest(int k, vector<int>& nums) {
        element = k;
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        vector<int> temp;
        for (int i = 0; i < element; i++) {
            temp.push_back(maxHeap.top());
            maxHeap.pop();
        }
        int result = temp.back();
        for (int i = 0; i < temp.size(); i++) {
            maxHeap.push(temp[i]);
        }
        return result;
    }
};
