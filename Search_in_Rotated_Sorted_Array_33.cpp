class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size() - 1; 
        while (first <= last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[first] <= nums[mid]) { //左边有序
                if (nums[first] <= target && target < nums[mid])
                    last = mid - 1;
                else
                    first = mid + 1; 
            }else { //右边有序
                if (nums[mid] < target && target <= nums[last])
                    first = mid + 1;
                else
                    last = mid - 1;      
            }
        }
        return -1;     
    }
};
