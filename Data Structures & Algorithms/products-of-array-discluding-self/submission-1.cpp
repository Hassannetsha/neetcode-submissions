class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int product = 1;
      int ctn0 = 0;
      for(int i = 0;i <nums.size();i++){

        if(nums[i]!=0) 
          product*=nums[i];
        else
          ctn0++;
      }
      vector<int>ans;
      for(int i = 0;i<nums.size();i++){
        if(ctn0>=2||ctn0==1&&nums[i]!=0){
          ans.push_back(0);
        }
        else{
          int den = 1;
          if(nums[i]!=0)
            den = nums[i];
          ans.push_back(product/den);
        }
      }
      return ans;
    }
};
