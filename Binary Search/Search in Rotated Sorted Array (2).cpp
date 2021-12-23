//problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/
//idea: using just one single binary search, we decide were to go the big part (ex: {456} - 0123) or go to the small part (ex: 456 - {0123})
//      depending on whether the target and the cur binary search value fall on the same part or we need to swap to the other part
// O(logn), where n is the size of the input array

class Solution {
public:
      
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0 , hi = n - 1, mid;
        int frst = nums[0];
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            bool query_big = nums[mid] >= frst;
            bool target_big = target >= frst;
            if (query_big && target_big) { // we both fall on the big part
                if (target > nums[mid])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else {
                if (query_big) lo = mid + 1; // go to the other half
                else if (target_big) hi = mid - 1; // go to the other half
                else { // we both fall on the small part
                    if (target > nums[mid])
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
        }
        return -1;
    }
};
