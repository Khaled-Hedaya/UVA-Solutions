
// problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// idea: 1- find the min element of the array using Binary search and let say its index is (idx), then you have two increasing subarrays
//       from 0 to idx - 1 and from idx + 1 till end of the array
//       2- decide which part the target will be found in, and then do again a normal binary search to find if the target is found or not
// O(logn + logn) = O(2logn) => O(long)

class Solution {
public:
    
    int findMin(vector < int > &nums) {
        int n = (int)nums.size();
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[n - 1])
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
       
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int mn_idx = findMin(nums);
        if(nums[mn_idx] == target)
            return mn_idx;
        int lo, hi, mid;
	    if (target > nums[mn_idx] && target > nums[n - 1])
		    lo = 0 , hi = mn_idx - 1;
	    else
		    lo = mn_idx + 1 , hi = n - 1;
        
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};
