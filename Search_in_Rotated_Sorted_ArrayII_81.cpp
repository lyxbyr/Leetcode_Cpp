/*
*
*
*
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int first = 0, last = nums.size() - 1;
    while (first <= last) {
        const int mid = first + (last - first) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[first] < nums[mid]) {
            if (nums[first] <= target && target < nums[mid]) 
                last = mid -1;
            else
                first = mid + 1;
        } else if (nums[first] > nums[mid]) {
            if (nums[mid] < target && target <= nums[last])
                first = mid + 1;
            else
                last = mid - 1;   
        } else
            first++;       
      }
      return false;     
    }
};


