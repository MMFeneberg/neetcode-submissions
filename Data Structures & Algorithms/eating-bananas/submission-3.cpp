class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = -1;
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left)/2;
            int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                int j = piles[i];
                //cout << " j: " << j << " mid: " << mid << "\n";
                hours = hours + std::ceil((double)j/mid);
                //cout << hours << "\n";
            }
            if (hours > h) {
                left = mid + 1;
            } else {
                if (mid != 0) {
                    mini = mid;
                }
                right = mid - 1;
            }
        }
        return mini;
    }


};
