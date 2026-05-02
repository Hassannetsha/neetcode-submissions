class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r= nums.size()-1;
        int piv = -1;
        while(l<=r){
            if (nums[l] <= nums[r]) {
                break;
            }
            int m = (l+r)/2;
            // res = min(res, nums[m]);
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        piv = l;
        l = 0,r= piv;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        l = piv,r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return -1;
    }
};
